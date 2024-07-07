### Overview
This is a development of a inventory management system that tracks lists of items in a particular local store. 
Typically designed for store clerks or store managers to update their current existing stocks or add extra items to a new category.
The core of the codebase will be build based on C++.
### How to use the program
Note: This program is currently designed for macOS users. Cross-platform will come at a later time
#### Dependencies
1. you're going to install glfw, install it on your terminal using ``brew install glfw``
2. also install cmake using ``brew install cmake``

#### Usage
1. clone the repo using ``git clone https://github.com/devhaocui/inventory-management-system.git``
2. use ``cmake ..`` inside of the ``/build`` directory to build the necessary files.
3. use ``make`` inside of the ``/build`` directory to build the executable ``./inv``.
4. run the program in terminal with ``./inv``.

### Desired Outcomes
- [x] Create a working inventory management system with C++ that stores item data locally using a .csv file.
- [x] Create a user registration and login feature using basic hashing algorithm to validate each user.
- [x] Implement the working codebase to display all the features inside of a GUI using ImGui with GLFW + OpenGL3.
- [ ] Modify the local storage .csv files into SQLite and integrate it into an actual database.

### Next Priority
- [In Progress] get all the existing functions to implement into ImGui structure.

### Known Issues
- [ ] Program crashes when attempting to add an non-integer value as a Quantity.
- [ ] Most of the current functions could refactor to increase performance. (Not a big deal yet).
