https://github.com/devhaocui/inventory-management-system/assets/172475135/81f277bf-b7ec-43f0-bcd1-c22891ce667a

### Overview
This is a development of a inventory management system that tracks lists of items in a particular local store. 
Typically designed for store clerks or store managers to update their current existing stocks or add extra items to a new category.
The core of the codebase will be build based on C++.

The password hashing algorithm used is bcrypt. Below is a photo example of 

``user name = myname`` and ``password = isjeff``
![username_demo](https://github.com/devhaocui/inventory-management-system/assets/172475135/d35e46ac-17c8-43bf-ad79-aec50acf2ac4)
### How to use the Program
1. I have made a simple easy to use MacOS bundle named ``inv.app`` included in the ``/invManSys`` directory.
2. Pull it out to your ``/Desktop`` directory. Then run this command in the terminal
 ``xattr -d com.apple.quarantine ./Desktop/inv.app`` to grant access for the app to be opened. This is due to the app not officially published into the app store.
3. Then just double click to open ``inv.app`` and you can play with it!

You can run ``inv.app`` completely independently without any files or libraries included in this GitHub. They're just there so you can see the source code.

### What the program does
- [x] Create a working inventory management system with C++ that stores item data locally using a .csv file.
- [x] Create a user registration and login feature using basic hashing algorithm to validate each user.
- [x] Implement the working codebase to display all the features inside of a GUI using ImGui with GLFW + OpenGL3.
- [x] Keyboard shortcuts such as using 1~9 keyboard to navigate the menu, ESC to go back, ENTER to confirm information.
- [ ] Modify the local storage .csv files into SQLite and integrate it into the database.

https://github.com/user-attachments/assets/b5cefc01-0616-421a-a80c-8d3886804765

### Known Issues
- [x] Program currently crashes whenever an empty value is inserted (exception for login/register functions). Will fix this issue by adding try and catch methods later.
