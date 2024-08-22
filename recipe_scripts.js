document.addEventListener("DOMContentLoaded", () => {
    const recipeList = document.getElementById("recipeList");
    const addRecipeBtn = document.getElementById("addRecipeBtn");
    const recipeFormContainer = document.getElementById("recipeFormContainer");
    const recipeForm = document.getElementById("recipeForm");

    // Example Recipe Data (Can be fetched from a backend)
    let recipes = JSON.parse(localStorage.getItem("recipes")) || [];

    function displayRecipes() {
        recipeList.innerHTML = "";
        recipes.forEach((recipe, index) => {
            const li = document.createElement("li");
            li.className = "list-group-item d-flex justify-content-between align-items-center";
            li.innerHTML = `
                ${recipe.name}
                <span>
                    <button class="btn btn-sm btn-primary mr-2 edit-btn" data-index="${index}">Edit</button>
                    <button class="btn btn-sm btn-danger delete-btn" data-index="${index}">Delete</button>
                </span>
            `;
            recipeList.appendChild(li);
        });

        // Attach event listeners for edit and delete buttons
        const editButtons = document.querySelectorAll('.edit-btn');
        const deleteButtons = document.querySelectorAll('.delete-btn');

        editButtons.forEach(button => {
            button.addEventListener('click', function () {
                const index = this.getAttribute('data-index');
                editRecipe(index);
            });
        });

        deleteButtons.forEach(button => {
            button.addEventListener('click', function () {
                const index = this.getAttribute('data-index');
                deleteRecipe(index);
            });
        });
    }

    function addRecipe(recipe) {
        recipes.push(recipe);
        localStorage.setItem("recipes", JSON.stringify(recipes));
        displayRecipes();
    }

    function deleteRecipe(index) {
        recipes.splice(index, 1);
        localStorage.setItem("recipes", JSON.stringify(recipes));
        displayRecipes();
    }

    function editRecipe(index) {
        const recipe = recipes[index];
        document.getElementById("recipeName").value = recipe.name;
        document.getElementById("recipeIngredients").value = recipe.ingredients;
        document.getElementById("recipeInstructions").value = recipe.instructions;
        recipeFormContainer.style.display = "block";
        addRecipeBtn.style.display = "none";

        recipeForm.onsubmit = function (event) {
            event.preventDefault();
            recipes[index] = {
                name: document.getElementById("recipeName").value,
                ingredients: document.getElementById("recipeIngredients").value,
                instructions: document.getElementById("recipeInstructions").value
            };
            localStorage.setItem("recipes", JSON.stringify(recipes));
            displayRecipes();
            resetForm();
        };
    }

    function resetForm() {
        recipeForm.reset();
        recipeFormContainer.style.display = "none";
        addRecipeBtn.style.display = "block";
    }

    // Event Listener for Adding New Recipe
    addRecipeBtn.addEventListener("click", () => {
        recipeFormContainer.style.display = "block";
        addRecipeBtn.style.display = "none";
        recipeForm.onsubmit = function (event) {
            event.preventDefault();
            const newRecipe = {
                name: document.getElementById("recipeName").value,
                ingredients: document.getElementById("recipeIngredients").value,
                instructions: document.getElementById("recipeInstructions").value
            };
            addRecipe(newRecipe);
            resetForm();
        };
    });

    // Initial Display
    displayRecipes();
});