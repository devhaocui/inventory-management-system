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
  //NOTE: I only care about if iName exists and iQuantity.
  std::vector<std::string> vec1;
  std::fstream myFile;
  myFile.open("item.csv", std::ios::in);
  std::string line;
  
  //putting the entire item.csv file into the vec1
  while (getline (myFile, line, ',') ) {
    vec1.push_back(line);
  }
  myFile.close();

  bool isItemAdded = false;
  for (size_t i{0} ; i < vec1.size(); i++) {
    if (iName == vec1[i]) {
      isItemAdded = true;
      vec1[i + 2] = std::to_string(std::stoi(vec1[i + 2]) + iQuantity);
      myFile.open("item.csv", std::ios::out);
      for (size_t i{0}; i < vec1.size(); i++) {
        std::cout << "inserting " << vec1[i] << " into myFile\n";
        myFile << vec1[i] << ",";
      }
      myFile.close();
    }

  }
  if (!isItemAdded || vec1.empty()) {
    myFile.open("item.csv", std::ios::app);
    myFile << iName << "," << iCategory << "," << iQuantity << ",";
    myFile.close();
  }
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
