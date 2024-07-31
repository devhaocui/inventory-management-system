#include "inventoryManagement.h"
#include <bcrypt.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sqlite3.h>

// class invManage -> of struct Item -> of a constructor Item call
invManage::Item::Item(std::string name, std::string category, int quantity)
    : itemName(name), itemCategory(category), itemQuantity(quantity) {}

void invManage::populate_stock() {
  std::vector<Item> vec;
  for (size_t i{0}; i < 100000; i++) {
    vec.push_back(Item("beef" + std::to_string(i), "food", 10));
    vec.push_back(Item("iphone" + std::to_string(i), "electronic", 10));
    vec.push_back(Item("couch" + std::to_string(i), "furniture", 10));
  }

  std::fstream file;
  std::string line;
  file.open("item.csv", std::ios::out);
  for (size_t i{0}; i < vec.size(); i++) {
    file << vec[i].itemName << ",";
    file << vec[i].itemCategory << ",";
    file << std::to_string(vec[i].itemQuantity) << ",";
  }
  file.close();
}

std::vector<std::string>
invManage::readDataIntoVectorUser(std::string fileName) {
  std::vector<std::string> vec;
  std::fstream file;
  std::string line;
  file.open(fileName, std::ios::in);
  while (getline(file, line, ','))
    vec.push_back(line);
  file.close();
  return vec;
}

std::vector<invManage::Item>
invManage::readDataIntoVector(std::string fileName) {
  std::vector<invManage::Item> vec;
  std::fstream file;
  std::string line;
  file.open(fileName, std::ios::in);
  int element_count{0};
  std::string element_one;
  std::string element_two;
  int element_three;
  while (getline(file, line, ',')) {
    if (element_count == 0) {
      element_one = line;
      element_count++;
    } else if (element_count == 1) {
      element_two = line;
      element_count++;
    } else if (element_count == 2) {
      element_three = std::stoi(line);
      vec.push_back(Item(element_one, element_two, element_three));
      element_count = 0;
    }
  }
  file.close();

  return vec;
}

std::unordered_map<std::string, std::vector<invManage::Item>>
readDataIntoMap(std::string fileName) {
  std::unordered_map<std::string, std::vector<invManage::Item>> myMap;
  return myMap;
}
// TODO:
// create an unordered_map that reads into the file,
// inventory all of the items with the same category as keys
// inventory all structs that belong to the same keys

bool invManage::userCreate() {
  bool userExist = false;
  std::cout << "userCreate() Function called\n";
  std::string password = bcrypt::generateHash(userPass);
  std::vector<std::string> file = readDataIntoVectorUser("user.csv");
  for (size_t i{0}; i < file.size(); i += 2) {
    if (userName == file[i]) {
      std::cout
          << "Registeration \x1b[31m[Failed]\x1b[0m. The username \x1b[31m("
          << userName << "\x1b[0m) already exists!\n";
      userExist = true;
      return false;
    }
  }
  if (!userExist) {
    if (userName == "") {
      std::cout
          << "\x1b[31m[Failed] \x1b[32mUsername cannot be empty!\x1b[0m\n";
      return false;
    }
    if (userPass == "") {
      std::cout << "\x1b[31m[Failed \x1b[32mPassword cannot be empty!\x1b[0m\n";
      return false;
    }
    std::cout << "\x1b[32m[Success]\x1b[0m Your account has been created!\n";
    std::cout << "Your Username is: \x1b[32m" << userName
              << "\x1b[0m\nYour Password is: \x1b[32m" << userPass
              << "\x1b[0m\n";
    std::fstream myFile;
    file.push_back(userName);
    file.push_back(password);
    for (size_t i{0}; i < file.size(); i += 2) {
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
  std::vector<std::string> userFile = readDataIntoVectorUser("user.csv");
  std::string password = userPass;
  for (size_t i{0}; i < userFile.size(); i += 2) {
    if (userName == userFile[i]) {
      bool validate = bcrypt::validatePassword(userPass, userFile[i + 1]);
      if (validate) {
        std::cout << "\x1b[32m[Success] login\x1b[0m\n";
        return true;
      } else {
        std::cout << "\x1b[31m[Success] login\x1b[0m\n";
        return false;
      }
    }
  }
  return false;
}

void invManage::addItem(std::string iName, std::string iCategory,
                        int iQuantity) {
  std::fstream file;
  std::vector<Item> vec = readDataIntoVector("item.csv");
  bool newItemAdded = false;
  for (size_t i{0}; i < vec.size(); i++) {
    // do this if there exists an item already...
    if (iName == vec[i].itemName) {
      newItemAdded = true;
      vec[i].itemQuantity += iQuantity;
      // write back into the file
      file.open("item.csv", std::ios::out);
      for (size_t i{0}; i < vec.size(); i++) {
        file << vec[i].itemName << ',' << vec[i].itemCategory << ','
             << vec[i].itemQuantity << ',';
      }
      file.close();
      std::cout << "Item add \x1b[32m[Success]\x1b[0m " << iName
                << " already exists in the database. Adding (" << iQuantity
                << ") " << iName << " more into the database.\nThere are now ("
                << vec[i].itemQuantity << ") " << iName
                << " in the inventory.\n";
      break;
    }
  }
  // do this if a new item needs to be added
  if (!newItemAdded || vec.empty()) {
    Item temp = invManage::Item(iName, iCategory, iQuantity);
    file.open("item.csv", std::ios::app | std::ios::ate);
    file << temp.itemName << ',' << temp.itemCategory << ','
         << temp.itemQuantity << ',';
    file.close();
  }
}

void invManage::deleteItem(std::string iName) {
  bool itemDeleted = false;
  std::vector<Item> vec = readDataIntoVector("item.csv");
  std::fstream file;
  std::string line;

  for (size_t i{0}; i < vec.size(); i++) {
    if (iName == vec[i].itemName) {
      itemDeleted = true;
      std::cout << "\x1b[32m[Deleted]\x1b[0m (" << iName
                << ") from the database.\n";
      vec.erase(vec.begin() + i);
      file.open("item.csv", std::ios::out);
      for (size_t i{0}; i < vec.size(); i++)
        file << vec[i].itemName << ',' << vec[i].itemCategory << ','
             << vec[i].itemQuantity << ',';
      file.close();
    }
  }
  if (!itemDeleted)
    std::cout << "\x1b[31m[Failed]\x1b[0m attempt at deleting an item that "
                 "does not exist in item!\n";
}

void invManage::withdrawItem(std::string iName, int withdrawAmount) {
  std::vector<invManage::Item> vec = readDataIntoVector("item.csv");
  for (size_t i{0}; i < vec.size(); i++) {
    // if iName matches with the vec[i].itemName
    if (iName == vec[i].itemName) {
      if (vec[i].itemQuantity - withdrawAmount < 0) {
        std::cout << "Withdrew \x1b[31m[Failed]\x1b[0m. You tried to withdraw ("
                  << withdrawAmount << ") " << iName
                  << " from the inventory.\n";
        std::cout << "There's (" << vec[i].itemQuantity << ") " << iName
                  << " left in the inventory.";
      } else {
        std::cout << "Withdrawing \x1b[32m(" << withdrawAmount << ")\x1b[0m "
                  << iName << " from the inventory\n";
        std::cout << "There's (" << vec[i].itemQuantity << ") " << iName
                  << " left in the inventory.";
        vec[i].itemQuantity -= withdrawAmount;
      }
    }
  }
  // write back into the file
  std::fstream file;
  file.open("item.csv", std::ios::out);
  for (size_t i{0}; i < vec.size(); i++) {
    file << vec[i].itemName << ',' << vec[i].itemCategory << ','
         << vec[i].itemQuantity << ',';
  }
  file.close();
}

// TODO: Convert this function into using struct Item
void invManage::searchItem(std::string iName) {
  bool itemFound = false;
  const int width = 10;
  std::vector<Item> vec = readDataIntoVector("item.csv");
  std::fstream file;
  std::string line;
  for (size_t i{0}; i < vec.size(); i++) {
    if (iName == vec[i].itemName) {
      itemFound = true;
      std::cout << "\n\x1b[32m=====Item Found=====\x1b[0m\n\x1b[33mItemName |"
                << std::setw(width) << " Category |" << std::setw(width)
                << " Quantity\n"
                << iName << std::setw(width + 3) << vec[i].itemCategory
                << std::setw(width + 2) << vec[i].itemQuantity << "\x1b[0m\n";
    }
  }
  if (!itemFound)
    std::cout << "Did not find (" << iName << ") in the inventory.\n";
}
