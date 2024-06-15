#include "inventoryManagement.h"

bool invManage::isNumber(std::string item) {
  for (size_t i{0}; i < item.size(); i++) {
    if (!isdigit(item[i]))
      return false;
  }
  return true;
}
void invManage::addItem (std::string iName, std::string iCategory, int iQuantity) {
  //TODO: Check if the item already exists, if so then add the quantity amount to that item.
  //1. we can use an <unordered_map> to grab all the items. 
  //2. we check if the item is in the map as we add more items into the map.

  std::unordered_map<std::string, int> myMap;

  std::cout << "iName -> " << iName << "\tiCategory -> " << iCategory << "\tiQuantity -> " << iQuantity;
  std::fstream inFile;
  inFile.open("item.csv", std::ios::app);
  inFile << iName << "," << iCategory << "," << iQuantity << std::endl;
  inFile.close();
}

void invManage::userOptionMenu() {
  short int userInput;
  std::cout << "Option 1: \n";
  std::cout << "Option 2: \n";
  std::cout << "Option 3: Add An Item \n";
  //std::cout << "Option 4: Remove An Item\n";

  std::cout << "Choose your option\n";
  std::cin >> userInput;

  switch (userInput) {
    case 1:
      std::cout << "userInput -> " << userInput;
    break;
    case 2:
      std::cout << "userInput -> " << userInput;
    break;
    case 3:
      std::string itemName, itemCategory;
      int itemQuantity;
      std::cout << "add an item in the following order, (1)Name (2)Category (3)Quantity\n";
      std::cin >> itemName >> itemCategory >> itemQuantity;
      for (size_t i{0}; i < itemName.size(); i++)
        itemName[i] = tolower(itemName[i]);
      for (size_t i{0}; i < itemCategory.size(); i++)
        itemCategory[i] = tolower(itemCategory[i]);

    addItem(itemName, itemCategory, itemQuantity);
    break;
  }
}
