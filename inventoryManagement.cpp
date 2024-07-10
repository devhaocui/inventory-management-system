#include <iostream>
#include <fstream>
#include <iomanip>
#include "inventoryManagement.h"
#include "bcrypt.h"

std::vector<std::string> invManage::readDataIntoVector(std::string fileName) {
  std::vector<std::string> vec;
  std::fstream file;
  std::string line;
  file.open(fileName, std::ios::in);
  while (getline(file, line, ','))
    vec.push_back(line);
  file.close();
  return vec;
}

void invManage::writeDataIntoVector(std::vector<std::string> vec, std::string iName, std::string iCategory, int iQuantity) {
}

bool invManage::userCreate() {
  bool userExist = false;
  std::cout << "userCreate() Function called\n";
  //std::cout << "Insert \x1b[32m(1)Username (2)Password\x1b[0m\n";
  //std::cin >> userName >> userPass;
  
  std::string password = bcrypt::generateHash(userPass);

  std::vector<std::string> file = readDataIntoVector("user.csv");
  for (size_t i{0}; i < file.size(); i += 2) {
    if (userName == file[i]) {
      std::cout << "Registeration \x1b[31m[Failed]\x1b[0m. The username \x1b[31m(" << userName << "\x1b[0m) already exists!\n";
      userExist = true;
      return false;
    }
  }
  if (!userExist) {
    if (userName == "") {
      std::cout << "\x1b[31m[Failed] \x1b[32mUsername cannot be empty!\x1b[0m\n";
      return false;
    }
    if (userPass == "") {
      std::cout << "\x1b[31m[Failed \x1b[32mPassword cannot be empty!\x1b[0m\n";
      return false;
    }
    std::cout << "\x1b[32m[Success]\x1b[0m Your account has been created!\n";
    std::cout << "Your Username is: \x1b[32m" << userName << "\x1b[0m\nYour Password is: \x1b[32m" << userPass << "\x1b[0m\n";
    std::fstream myFile;
    file.push_back(userName);
    file.push_back(password);
    for (size_t i{0} ; i < file.size(); i += 2) {
      myFile.open("user.csv", std::ios::out);
      for (size_t i{0}; i < file.size(); i++) {
        myFile << file[i];
          if (i < file.size() - 1)
            myFile << ",";
        }
        myFile.close();
      }
    }
    return true;
  }

bool invManage::userValidate(std::string userName, std::string userPass) {
  std::vector<std::string> userFile = readDataIntoVector("user.csv");
  std::string password = userPass;
  for (size_t i{0}; i < userFile.size(); i += 2) {
    if (userName == userFile[i]) {
      bool validate = bcrypt::validatePassword(userPass, userFile[i + 1]);
      if (validate) {
        std::cout << "\x1b[32m[Success] login\x1b[0m\n";
        return true;
      }
      else {
        std::cout << "\x1b[31m[Success] login\x1b[0m\n";
        return false;
      }
    }
  }
  return false;
}

void invManage::addItem (std::string iName, std::string iCategory, int iQuantity) {
  std::vector<std::string> vec;
  std::fstream myFile;
  myFile.open("item.csv", std::ios::in);
  std::string line;
  
  //putting the entire item.csv file into the vec
  while (getline(myFile, line, ',')){
    vec.push_back(line);
  }
  myFile.close();

  bool isItemAdded = false;
  for (size_t i{0} ; i < vec.size(); i++) {
    if (iName == vec[i]) {
      isItemAdded = true;
      vec[i + 2] = std::to_string(std::stoi(vec[i + 2]) + iQuantity);
      std::cout << "Item add \x1b[32m[Success]\x1b[0m " << iName << " already exists in the database. Adding (" << iQuantity << ") " << iName 
                << " more into the database.\nThere are now (" << vec[i + 2] << ") "<< iName << " in the store.\n";
      break;
    }
  }

  if (!isItemAdded || vec.empty()) {
    vec.push_back(iName);
    vec.push_back(iCategory);
    vec.push_back(std::to_string(iQuantity));
  }

  myFile.open("item.csv", std::ios::out);
  for (size_t i{0}; i < vec.size(); i++) {
    myFile << vec[i];
    if (i < vec.size() - 1)
      myFile << ",";
  }
  myFile.close();
}

void invManage::deleteItem (std::string iName) {
  bool itemDeleted = false;
  std::vector<std::string> vec;
  std::fstream myFile;
  std::string line;
  myFile.open("item.csv", std::ios::in);
  //putting the entire item.csv file into the vec
  while (getline(myFile, line, ',')){
    vec.push_back(line);
  }
  myFile.close();

  for (size_t i{0} ; i < vec.size(); i += 3) {
    if (iName == vec[i]) {
      itemDeleted = true;
      std::cout << "\x1b[32m[Deleted]\x1b[0m (" << iName << ") from the database.\n";
      vec.erase(vec.begin() + i,vec.begin() + i + 3);
      myFile.open("item.csv", std::ios::out);
      for (size_t i{0}; i < vec.size(); i++) {
        myFile << vec[i];
        if (i < vec.size() - 1)
          myFile << ",";
      }
      myFile.close();
    }
  }
  if (!itemDeleted)
    std::cout << "\x1b[31m[Failed]\x1b[0m attempt at deleting an item that does not exist in item!\n";
}

void invManage::withdrawItem (std::string iName, int withdrawAmount) {
  std::vector<std::string> vec;
  std::string line;
  std::fstream myFile;
  myFile.open("item.csv", std::ios::in);
  while (getline(myFile, line, ','))
    vec.push_back(line);
  myFile.close();
 
  for (size_t i{0}; i < vec.size(); i += 3) {
    if (iName == vec[i]) {
      if (std::stoi(vec[i + 2]) - withdrawAmount < 0) {
        std::cout << "Withdrew \x1b[31m[Failed]\x1b[0m. You tried to withdraw (" << withdrawAmount << ") " << iName << " from the store.\n";
        std::cout << "There's (" << vec[i + 2] << ") " << iName << " left in the store.";
      }
      else {
        std::cout << "Withdrawing \x1b[32m(" << withdrawAmount << ")\x1b[0m " << iName << " from the store\n";
        vec[i + 2] = std::to_string(std::stoi(vec[i + 2]) - withdrawAmount);
        std::cout << "You have \x1b[32m(" << vec[i + 2] << ")\x1b[0m " << iName << " left in the store.\n";
        myFile.open("item.csv", std::ios::out);
        for (size_t i{0}; i < vec.size(); i++) {
          myFile << vec[i] << ",";
        }
        myFile.close();
        break;
      }
    }
  }
}

void invManage::searchItem(std::string iName) {
  bool itemFound = false;
  const int width = 10;
  std::vector<std::string> vec;
  std::fstream myFile;
  myFile.open("item.csv", std::ios::in);
  std::string line;
  while (getline(myFile, line, ',')){
    vec.push_back(line);
  }
  myFile.close();

  for (size_t i{0}; i < vec.size(); i += 3) {
    if (iName == vec[i]) {
      itemFound = true;
      std::cout << "\n\x1b[32m=====Item Found=====\x1b[0m\n\x1b[33mItemName |" 
                << std::setw(width) << " Category |" << std::setw(width) << " Quantity\n"
                << iName << std::setw(width+3) << vec[i + 1] << std::setw(width+2) << vec[i + 2] << "\x1b[0m\n";
    }
  }
  if (!itemFound)
    std::cout << "Did not find (" << iName << ") in the store.\n";
}

void invManage::displayCategory(std::string iCategory) {
  std::vector<std::string> vec;
  std::fstream myFile;
  myFile.open("item.csv", std::ios::in);
  std::string line;
  while (getline(myFile, line, ',')){
    vec.push_back(line);
  }
  myFile.close();
  std::cout << "\x1b[33m===== displaying " << iCategory << " category =====\n";
  std::cout << "Name |" << std::setw(10) << " Category |" << std::setw(10) << " Quantity\n";
  for (size_t i{0}; i < vec.size(); i += 3) {
    if (iCategory == vec[i+1])
      std::cout << vec[i] << " | " << vec[i+1] << " | " << vec[i+2] << "\n";
  }
  std::cout << "\x1b[0m";
}

// PERF: MENU FUNCTIONS GOES HERE
void invManage::mainMenu() {
  short int userInput;
  std::cout << "\n\x1b[32m==========mainMenu()==========\n"
            << "Option 1: Create Account\n"
            << "Option 2: Login Account\n"
            << "Option 3: Forgot Password\n"
            << "Choose your option\n"
            << "------------------------------\x1b[0m  \n";
  std::cin >> userInput;
  switch (userInput) {
    case 1: {
      userCreate();
      break;
    }
    case 2: {
      std::cout << "Input \x1b[32m(1)UserName (2)Password\x1b[0m\n";
      std::cin >> userName >> userPass;
      bool validation = userValidate(userName, userPass);
      if (validation) {
        std::cout << "\n\x1b[32m[Success]\x1b[0m validation! You are logged in!\n";
        userOptionMenu();
      }
      else
        std::cout << "\n\x1b[31m[Failure]\x1b[0m validation failed! You are not logged in!\n";
      break;
    }
    case 3: {
      //TODO: implmenet userForgotPass() function.
      break;
    }

    default: {
      std::cout << "executed default case\n";
      break;
    }
  }
}

void invManage::userOptionMenu() {
  short int userInput;
  std::string itemName, itemCategory;
  int itemQuantity;

  while (true) {
    std::cout << "\n\x1b[32m===========userOptionMenu()=========\n"
              << "Option 1: Add an item \n"
              << "Option 2: Delete an item\n"
              << "Option 3: Withdraw an item\n"
              << "Option 4: Search for an item\n"
              << "Option 5: Display all items\n"
              << "Option 6: Display by category\n"
              << "Choose your option\n"
              << "------------------------------------\x1b[0m\n";
    std::cin >> userInput;

    switch (userInput) {
      case 1:
        std::cout << "add an item in the following order, \x1b[32m(1)ItemName (2)Category (3)Quantity\x1b[0m\n";
        std::cin >> itemName >> itemCategory >> itemQuantity;
        for (size_t i{0}; i < itemName.size(); i++)
          itemName[i] = tolower(itemName[i]);
        for (size_t i{0}; i < itemCategory.size(); i++)
          itemCategory[i] = tolower(itemCategory[i]);
        addItem(itemName, itemCategory, itemQuantity);
        break;

      case 2:
        std::cout << "Input \x1b[32m(1)ItemName\x1b[0m to be deleted from the list\n";
        std::cin >> itemName;
        deleteItem(itemName);
        break;
      case 3:
        std::cout << "Input \x1b[32m(1)ItemName (2)ItemQuantity\x1b[0m to withdraw\n";
        std::cin >> itemName >> itemQuantity;
        withdrawItem(itemName, itemQuantity);
        break;
      case 4:
        std::cout << "Input \x1b[32m(1)ItemName\x1b[0m to start searching\n";
        std::cin >> itemName;
        searchItem(itemName);
        break;
      case 5:
        display();
        break;
      case 6:
        std::cout << "Input \x1b[32m(1)Category\x1b[0m Name to start displaying\n";
        std::cin >> itemCategory;
        displayCategory(itemCategory);
        break;
    }
  }
}

void invManage::display() {
  std::vector<std::string> vec = readDataIntoVector("item.csv");
  std::cout << "\x1b[33m===============display()===============\n";
  std::cout << "Name |" << std::setw(10) << " Category |" << std::setw(10) << " Quantity\n";
  for (size_t i{0}; i < vec.size(); i += 3)
    std::cout << vec[i] << " | " << vec[i+1] << " | " << vec[i+2] << "\n";
  std::cout << "---------------------------------------\x1b[0m\n";
}
