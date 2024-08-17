https://github.com/devhaocui/inventory-management-system/assets/172475135/81f277bf-b7ec-43f0-bcd1-c22891ce667a

### Overview
This is a development of a inventory management system that tracks lists of items in a particular local store. 
Typically designed for store clerks or store managers to update their current existing stocks or add extra items to a new category.
The core of the codebase will be build based on C++.

The password hashing algorithm used is bcrypt. Below is a photo example of 

``user name = myname`` and ``password = isjeff``
![username_demo](https://github.com/devhaocui/inventory-management-system/assets/172475135/d35e46ac-17c8-43bf-ad79-aec50acf2ac4)
### How to use the program
Note: This program is currently designed for macOS users. It may or may not work for other Operating Systems. 
#### Dependencies
1. all dependencies are checked and installed in ``start.sh`` script. But some dependencies are Brew, GLFW, OpenGL, CMake.
#### Usage
1. download the repo using ``git clone https://github.com/devhaocui/inventory-management-system.git``
2. run the ``start.sh`` executable in the terminal.

### Desired Outcomes
- [x] Create a working inventory management system with C++ that stores item data locally using a .csv file.
- [x] Create a user registration and login feature using basic hashing algorithm to validate each user.
- [x] Implement the working codebase to display all the features inside of a GUI using ImGui with GLFW + OpenGL3.
- [x] Keyboard shortcuts such as using 1~9 keyboard to navigate the menu, esc to go back, enter to confirm information.
- [ ] Modify the local storage .csv files into SQLite and integrate it into the database.

https://github.com/user-attachments/assets/b5cefc01-0616-421a-a80c-8d3886804765

### Known Issues
- [x] Program currently crashes whenever an empty value is inserted (exception for login/register functions). Will fix this issue by adding try and catch methods later.
