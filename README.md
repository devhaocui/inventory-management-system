OVERVIEW:
This is a development of a inventory management system that tracks lists of items in a particular local store. 
Typically designed for store clerks or store managers to update their current existing stocks or add extra items to a new category.
The core of the codebase will be build based on C++.

DESIRED OUTCOME:
1. Create a working inventory management system with C++ that stores item data locally using a .csv file.
2. Create a user registeration and login feature using basic hashing algorithm to validate each user.
3. Implement the working codebase to display all the features inside of a GUI using ImGui with GLFW + OpenGL3.
4. Modify the local storage .csv files into SQLite and integrate it into an actual database.

WHAT IT CURRENT DOES:
1. add an item and automatically saves into the item.csv file from the terminal command prompts. If an item already exists in the file it will only add the quantity specified into the existing quantity.

NEXT PRIORITIES:
1. remove an existing item in item.csv file (if found).
2. print all items in the inventory.
3. print items based on a specific category.
