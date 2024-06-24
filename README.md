### Overview
This is a development of a inventory management system that tracks lists of items in a particular local store. 
Typically designed for store clerks or store managers to update their current existing stocks or add extra items to a new category.
The core of the codebase will be build based on C++.
### How to use the program
1. clone the repo using ``git clone https://github.com/devhaocui/inventory-management-system.git``
2. run the run.sh file using ``sh run.sh``
3. use ``cmake ..`` inside of the ``/build`` directory to build the necessary files.
4. use ``make`` inside of the ``/build`` directory to build the executable ``./inventory``.
5. run the program in terminal with ``./inventory``.

### Desired Outcomes
- [x] Create a working inventory management system with C++ that stores item data locally using a .csv file.
- [ ] Create a user registration and login feature using basic hashing algorithm to validate each user.
- [ ] Implement the working codebase to display all the features inside of a GUI using ImGui with GLFW + OpenGL3.
- [ ] Modify the local storage .csv files into SQLite and integrate it into an actual database.

### What the program currently does
- [x] add an item and automatically saves into the ``item.csv`` file from the terminal command prompts. If an item already exists in the file it will only add the quantity specified into the existing quantity.
- [x] deleteItem() function removes an item from the ``item.csv`` database.
- [x] withdrawItem() function withdraws the amount of items from ``item.csv``. Withdraw will fail if attempting to overdraft.
- [x] display() function to display all the items in the order they are originally added into the ``item.csv`` file.
- [x] displayCategory() print items based on specified category.
- [x] userCreate() creates a username and password using bcrypt slow hashing algorithm.
- [x] userLogin() asks for userName and Password and use bcrypt::validatePassword() to authenticate the hashed password.
- [x] mainMenu() main prompt to ask for registration and login.
- [x] colorized some of the terminal displays.

### Next Priorities
- [ ] print items based on itemName alphabetically. (probably insert item.csv into a tuple data structure)
- [ ] forgotPass() to allow password reset.
- [ ] implementation of ImGUI into the project.
