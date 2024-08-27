import os
from flask import Flask, render_template, request
import requests
from urllib.parse import unquote

# Create the flask app
app = Flask(__name__)

# API Key
API_KEY = os.getenv('API_KEY')

# Define the route for "Home" button
@app.route('/home', methods=['GET'])
def home():
    # Render main page with an empty recipe list and search query
    return render_template('explore.html', recipes=[], search_query='')

# Define the main route for the app
@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        # If a form is submitted
        query = request.form.get('search_query', '')
        # Perform a search for recipes with the given query
        recipes = search_recipes(query)
        # Render the main page 
        return render_template('explore.html', recipes=recipes, search_query=query)
    
    # If it's a GET request or no form submitted
    search_query = request.args.get('search_query', '')
    decoded_search_query = unquote(search_query)
    # Perform a search for recipes with the decoded query
    recipes = search_recipes(decoded_search_query)
    # Render the main page
    return render_template('explore.html', recipes=recipes, search_query=decoded_search_query)

# Function to search for recipes based on provided query
def search_recipes(query):
    url = f'https://api.spoonacular.com/recipes/complexSearch'
    params = {
        'apiKey': API_KEY,
        'query': query,
        'number': 10,
        'instructionsRequired': True,
        'addRecipeInformation': True,
        'fillIngredients': True
    }

    # Send a GET request to the Spoonacular API with the query params
    response = requests.get(url, params=params)
    # If the API call is successful
    if response.status_code == 200:
        # Parse the API response as JSON data
        data = response.json()
        # Return the list of recipe results
        return data['results']
    # If the API call is unsuccessful
    return[]

# Route to view a specific recipe with a given recipe ID
@app.route('/recipe/<int:recipe_id>')
def view_recipe(recipe_id):
    # Get the search query from the URL query params
    search_query = request.args.get('search_query','')
    # Build the URL to get info about the specific recipe ID from Spoonacular API
    url = f'https://api.spoonacular.com/recipes/{recipe_id}/information'
    params = {
        'apiKey': API_KEY,
    }

    # Send a GET request to the Spoonacular API to get the recipe info
    response = requests.get(url, params=params)
    # If the API call is successful
    if response.status_code == 200:
        recipe = response.json()
        return render_template('templates/view_recipes.html', recipe=recipe, search_query=search_query)
    return "Recipe not found", 404

# Run the app ind ebug mode if executed directly
if __name__ == '__main__':
    app.run(debug=True)