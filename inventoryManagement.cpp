#include "inventoryManagement.h"

//bool invManage::isNumber(std::string item) {
//  for (size_t i{0}; i < item.size(); i++) {
//    if (!isdigit(item[i]))
//      return false;
//  }
//  return true;
//}

void invManage::addItem (std::string iName, std::string iCategory, int iQuantity) {
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
      std::cout << iName << " already exist in the list. Adding (" << stoi(vec1[i+2]) << " + " << iQuantity << ")\n";
      break;
    }
  }

  if (!isItemAdded || vec1.empty()) {
    vec1.push_back(iName);
    vec1.push_back(iCategory);
    vec1.push_back(std::to_string(iQuantity));
  }

  myFile.open("item.csv", std::ios::out);
  for (size_t i{0}; i < vec1.size(); i++) {
    //std::cout << "inserting -> " << vec1[i] << "\n"; // for testing if it is inserting empty spaces
    myFile << vec1[i];
    if (i < vec1.size() - 1)
      myFile << ",";
  }
  myFile.close();
}

void invManage::deleteItem (std::string iName) {
  bool itemDeleted = false;
  std::vector<std::string> vec1;
  std::fstream myFile;
  myFile.open("item.csv", std::ios::in);
  std::string line;
  
  //putting the entire item.csv file into the vec1
  while (getline (myFile, line, ',') ) {
    vec1.push_back(line);
  }
  myFile.close();

  // if iName is found, delete the current values related to iName.
  // which are vec1[i], vec1[i+1], vec1[i+2]
  // Then put it back into the list
  for (size_t i{0} ; i < vec1.size(); i += 3) { // note: i+=3 means this skips the iCategory and iQuantity in the item.csv
    if (iName == vec1[i]) {
      itemDeleted = true;
      std::cout << "Deleted (" << iName << ") from the database.\n";
      vec1.erase(vec1.begin() + i,vec1.begin() + i + 3);
      myFile.open("item.csv", std::ios::out);
      for (size_t i{0}; i < vec1.size(); i++) {
        myFile << vec1[i];
        if (i < vec1.size() - 1)
          myFile << ",";
      }
      myFile.close();
    }
  }
  if (!itemDeleted)
    std::cout << "The item you wish to delete does not exist in the databse!\n";
}
void invManage::withdrawItem (std::string iName) {

}

void invManage::userOptionMenu() {
  short int userInput;
  std::string itemName, itemCategory;
  int itemQuantity;
  std::cout << "Option 1: \n";
  std::cout << "Option 2: \n";
  std::cout << "Option 3: Add An Item \n";
  std::cout << "Option 4: Delete An Item\n";

  std::cout << "Choose your option\n";
  std::cin >> userInput;

  switch (userInput) {
    case 1:
      std::cout << "userInput -> " << userInput;
      break;

    case 2:
      std::cout << "userInput -> " << userInput;
      break;

    case 3: {
      std::cout << "add an item in the following order, (1)ItemName (2)Category (3)Quantity\n";
      std::cin >> itemName >> itemCategory >> itemQuantity;
      for (size_t i{0}; i < itemName.size(); i++)
        itemName[i] = tolower(itemName[i]);
      for (size_t i{0}; i < itemCategory.size(); i++)
        itemCategory[i] = tolower(itemCategory[i]);
      addItem(itemName, itemCategory, itemQuantity);
      break;
    }
    case 4:
      std::cout << "Input (1)ItemName to be deleted from the list\n";
      std::cin >> itemName;
      deleteItem(itemName);
      break;
  }
}
