### Overview
This is a development of a inventory management system that tracks lists of items in a particular local store. 
Typically designed for store clerks or store managers to update their current existing stocks or add extra items to a new category.
The core of the codebase will be build based on C++.

### How to use the program
1. clone the repo using ``git clone https://github.com/devhaocui/inventory-management-system.git``
2. run the run.sh file using ``sh run.sh``
3. enjoy :).

### Desired Outcomes
- [ ] Create a working inventory management system with C++ that stores item data locally using a .csv file.
- [ ] Create a user registeration and login feature using basic hashing algorithm to validate each user.
- [ ] Implement the working codebase to display all the features inside of a GUI using ImGui with GLFW + OpenGL3.
- [ ] Modify the local storage .csv files into SQLite and integrate it into an actual database.

### What the program currently does
- [x] add an item and automatically saves into the item.csv file from the terminal command prompts. If an item already exists in the file it will only add the quantity specified into the existing quantity.

### Next Priorities
- [ ] remove an existing item in item.csv file (if found).
- [ ] print all items in the inventory.
- [ ] print items based on a specific category.
