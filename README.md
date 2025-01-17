[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=15529057)
 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# \Let Us Cook\
 > Your author list below should include links to all members GitHub (remove existing author).
 
 > Authors: \<[Jeffrey McDaniel](https://github.com/jmcda001)\>

 > You will be forming a group of **FOUR** students and working on an interesting project. The project has 4 phases, each one with specific requirements. A list of proposed project ideas that have been successful in previous quarters is listed in the project specifications document on Canvas. You can select an idea from the list and start thinking about the features you will implement. If you want to propose your own original idea, you will have to contact your instructor to discuss the project and obtain written permission before you submit your project proposal (Phase 1). The project work should be divided almost equally among team members. You can of course help each other, but it needs to be clear who will be responsible for which features. Additionally, you are expected to follow Scrum patterns, specifically the use of a Scrum (Project) board, Sprints, and Scrum meetings.

 > ## Expectations
 > * The backend of your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * **Each member of the group must actively participate in the Github Project board, writing unit tests, and reviewing commited code.**
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold two to three scrum/check-in meetings with your lab TA/reader at different times in addition to the final demo.

## Project Description
 > Your project description should summarize the project you are proposing. Be sure to include:
 > * Why is it important or interesting to you?
>  * This project is exciting because it lets us build something real that people can actually use to find and share recipes easily. It's a great way to see how our coding skills can come together to create a smooth, interactive experience for users.
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
>  * C++
 > * What will be the input/output of your project?
 > * What are the features that the project provides?
>  * Front-End Developer Contribution to Recipe Manager Project
Programming Languages: JavaScript, HTML/CSS
Styling Framework: Bootstrap
Dynamic Components: React.js
Responsibilities:
Website Layout Design:
Designing the overall layout of the website, ensuring it is visually appealing for users. 
Login and Registration Pages:
I will help in creating the front-end components for the login and registration pages. These components will be connected to the backend to handle user authentication.
Search and Filter Interface:
Design an interface that allows users to search recipes based on various criteria. This feature is crucial for helping users easily find specific recipes from the database.
Interactive Features:
Implement interactive features using JavaScript and use the dynamic components from React.js to help create reusability of the code for efficiency.
Code Documentation:
Regularly commit code to the project repository so that all front-end changes are documented and attributed correctly. This will help provide clear records of the development process.

>   * Back-End Developer
>    * **User Account Management: Handle user registration, login**
>    * Input: Username, password
>    * Output: user authentication tokens, success or error messages
>    * **Receipe Operations:**
>    * **Create Recipe: Allow users to add new recipes**
>    * Input: recipe details: name, ingredients, instructions, tags
>    * Output: confirmation message, recipe I
>    * **Read Recipe: Retrieve and display recipes from database**
>    * Input: Search queries, filters, Recipe ID
>    * Output: Recipe details (name, ingredients, instructions, tags)
>    * **Update Recipe: allow users to edit their existing recipes**
>    * Input: Recipe ID, updated recipe details
>    * Output: Confirmation message
>    * **Delete Recipe: Allow users to delete recipes**
>    * Input: Recipe ID
>    * Output: confirmation message, error messages if it does not exist
>    * **User Profile Management: Store and manage user data, saved recipes, personal details…**
>    * Input: User ID, profile updates
>    * Output: updated user profile data, confirmation message
>    * **Recipe Rating and Reviews:**
>    * Input: Recipe ID, user rating (1-5 stars), review text
>    * Output: Updated recipe rating, list of recent reviews
>    * **Recipe Search and Filtering**
>    * Input: search queries, filter options
>    * Output: list of matching recipes, sorted based on relevance
>
>    1. Routing and Request Handling
>    * Define routes to manage different endpoints in the application (recipe search, and recipe details)
>    * Handle HTTP requests and render appropriate HTML templates
>    2. Template Rendering
>    * Use Flask templating engine to render HTML templates
>    * Dynamically inject content such as recipe lists, search results, and recipe details into the HTML pages
>    3. Data Management
>    * Manage data interactions, including fetching and passing data (recipe information) to templates for rendering
>    * Ensure data is correctly displayed and handled across different routes and pages
>    4. Search and Filtering Logic
>    * Implement search functionality that allows users to search for recipes based on keywords
>    * Process search queries, filter results, and render the filtered list of recipes
>    6. Error Handling
>    * Implement error handling for missing templates, invalid routes, and other potential issues
>    * Provide user-friendly messages and fallback options in case of errors



 > This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 
 > 
 > You also need to set up an empty project board using GitHub projects (board view with default columns). Make sure you add the board under your project repository. You should also have a Product Backlog and In testing columns added. All columns should be in the right order.
 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column (aka Sprint Backlog).
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. Both time slots should be during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.

### Screen Layouts
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs and expected output, or any graphical user interface components if applicable (e.g. buttons, text boxes, etc). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.
> added navigation diagram file in repo

## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides). <img width="440" alt="image" src="https://github.com/user-attachments/assets/50d024e1-7bbc-4ff1-9282-17d6e31efb2e">

 The class diagram provides an overview of the primary components in the "Let Us Cook" project and how they interact with each other. Below is a detailed explanation of each class:

1. **Recipe Class:**
   - The `Recipe` class encapsulates the details of a recipe, including its name, ingredients, instructions, and tags. It provides methods for serializing the recipe into a string format for storage and deserializing it back into a `Recipe` object.

2. **User Class:**
   - The `User` class represents a user in the system. It stores the user's `username`, a hashed version of their `password`, and a list of `savedRecipes` (referenced by Recipe IDs). The `User` class also provides methods for user authentication and managing saved recipes.

3. **RecipeManager Class:**
   - The `RecipeManager` class handles the operations related to recipe management. It maintains a `recipeDatabase` that stores recipes identified by a unique `RecipeID`. The class includes methods for creating, reading, updating, and deleting recipes, as well as searching for recipes based on user queries.

4. **UserManager Class:**
   - The `UserManager` class is responsible for managing user-related operations. It maintains a `userDatabase` where each user is identified by their `username`. The class provides methods for user registration, login, and updating user profiles. It also allows for retrieving a user's profile details.

### Relationships and Interactions:
- **RecipeManager**: This class interacts with the `Recipe` class by performing CRUD operations on the `recipeDatabase`. It ensures that recipes are correctly stored, updated, retrieved, and deleted.
- **UserManager**: The `UserManager` class interacts with the `User` class by handling user authentication and profile management. It maintains a `userDatabase` and ensures secure handling of user information.
- **User-Recipe Relationship**: Each `User` can save multiple recipes, identified by their `RecipeID`. This creates a link between the `User` and the `Recipe` classes, managed by the `UserManager`.

This diagram and description outline the core structure of the "Let Us Cook" project, highlighting how data flows between classes and how responsibilities are distributed across different components.

 
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
>      * Single Responsibility Principle, Open/Closed Principle, Liskov Substitution Principle, Interface Segregation Principle, Dependency Inversion Principle
 >     * How did you apply it? i.e. describe the change.
>      * "Single Responsibility Principle": By separating the responsibilities of user management and recipe management into distinct classes, the code became more modular and easier to maintain.
>      * "Open/Closed Principle": For example, if new types of recipes or user roles need to be added, this can be done by extending existing classes rather than modifying them.
>      * "Liskov Substitution Principle": For instance, in the user management system, any subclass of a User should be usable wherever a User object is expected, without introducing errors.
>      * "Interface Segregation Principle": For example, separate interfaces were created for user authentication and recipe management rather than having a single interface that does everything.
>      * "Dependency Inversion Principle": For example, instead of the UserManager class depending directly on a specific database implementation, it depends on an abstract interface that can be implemented by any database class.
 >     * How did this change help you write better code?
>      * "Single Responsibility Principle": This change improved the code's readability and maintainability, making it easier to update or extend functionality without affecting other parts of the system.
>      * "Open/Closed Principle": This approach minimizes the risk of introducing bugs into existing functionality and makes it easier to implement new features.
>      * "Liskov Substitution Principle": This ensures that the code remains reliable and flexible, allowing for future extensions without breaking existing functionality.
>      * "Interface Segregation Principle": This segregation makes the code more modular and reduces the complexity for classes that implement these interfaces, leading to more focused and manageable code.
>      * "Dependency Inversion Principle": This inversion of dependency makes the system more flexible and easier to refactor. It also allows for easier testing by enabling the use of mock objects in place of actual database connections during unit tests.
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
> What I Did (Stella)
> 1. Project Structure 
> * The main directories include:
>     * .vscode: Contains configuration files for Visual Studio Code, including c_cpp_properties.json and settings.json.
>     * backend: Contains the core source code and configurations for the backend.
>     * config: Holds configuration files like db_config.json that store database connection details.
>     * src: Contains the source code files that implement the functionality of your application.
2. .vscode Directory
> * c_cpp_properties.json: This file configures the include paths, compiler settings, and IntelliSense for C++ projects in Visual Studio Code. It helps in setting up the environment so that the IDE understands the project structure and dependencies.
> * settings.json: Stores project-specific settings for Visual Studio Code, such as formatting rules, linting, and other preferences.
3. backend Directory
> * config/db_config.json:
>     * This file stores the database configuration settings such as the hostname, port, username, password, and database name. It’s a centralized location for managing database connection details that your Database class uses to connect to the MySQL server.
4. src Directory
> * bcrypt.cpp & bcrypt.h:

>    * These files handle password hashing using the bcrypt algorithm. The bcrypt algorithm is used to securely hash passwords before storing them in the database. The .cpp file implements the functions declared in the .h header file. These files are essential for ensuring that passwords are stored securely and are not exposed in plain text.
> * Database.cpp & Database.h:

>    * Database.h declares the Database class, which is responsible for managing the connection to the MySQL database and performing SQL operations like queries and updates.
Database.cpp implements the Database class. It includes methods for connecting to the database, executing SQL queries, and fetching results. It ensures the backend can interact with the MySQL database to store and retrieve data.
> * jwt.cpp & jwt.h:

>    * These files manage JSON Web Tokens (JWTs), which are used for securely transmitting information between the frontend and backend. JWTs are typically used for authentication purposes, ensuring that the user making a request is authenticated.
The .h file declares the functions and classes related to JWT handling, and the .cpp file implements these functions.
> * main.cpp:

>    * This is the entry point of your application. It likely contains the main function that initializes the application, sets up the necessary services (like the database connection), and handles user input for registering and logging in.
>     * This file coordinates the execution of various parts of the backend and interacts with the user, likely through a command-line interface.
> * Recipe.cpp & Recipe.h:

>    * Recipe.h defines the Recipe class, which encapsulates the details of a recipe, such as its name, ingredients, instructions, and tags. This class provides methods for managing recipe details.
>    * Recipe.cpp implements the Recipe class, providing the logic for handling recipes, such as converting ingredients and tags to and from strings for storage in the database.
> * RecipeManager.cpp & RecipeManager.h:

>    * RecipeManager.h declares the RecipeManager class, which is responsible for managing the collection of recipes. It includes methods for creating, reading, updating, and deleting recipes in the database.
>     * RecipeManager.cpp implements the RecipeManager class, providing the logic for interacting with the Recipe class and the database to manage recipes effectively.
> * UserManager.cpp & UserManager.h:

>    * UserManager.h declares the UserManager class, which handles user-related operations like registration, login, and profile management.
>    * UserManager.cpp implements the UserManager class. It contains the logic for securely handling user data, such as hashing passwords, validating user credentials, and interacting with the Database class to manage user information.
5. CMakeLists.txt
> * CMakeLists.txt is the build configuration file for your project. It sets up the CMake build system, specifying the C++ standard, including necessary directories, and linking the required libraries such as OpenSSL and MySQL.
> * This file ensures that all the source files are compiled and linked together correctly to create the final executable.

Summary
> * I have set a backend system for managing user accounts and recipes, utilizing C++ for the core logic, bcrypt for secure password hashing, and MySQL for data storage.
> * The main.cpp file serves as the entry point, coordinating interactions between users and the backend services.
> * The backend is modular, with distinct classes handling different aspects of the application (e.g., Recipe, User, Database), following the principles of encapsulation and separation of concerns.
> * CMake is used to manage the build process, ensuring that all dependencies are properly included and linked.
> * I ensured the codebase is maintainable, scalable, and secure. 


 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
