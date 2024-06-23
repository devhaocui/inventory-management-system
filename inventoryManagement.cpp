#include "inventoryManagement.h"

std::vector<std::string> invManage::readDataIntoVector(std::string fileName) {
  std::vector<std::string> vec;
  std::fstream myFile;
  std::string line;
  myFile.open(fileName, std::ios::in);
  while (getline(myFile, line, ','))
    vec.push_back(line);
  myFile.close();
  return vec;
}

void invManage::userCreate() {
  bool userExist = false;
  std::cout << "Insert (1)Username (2)Password\n";
  std::cin >> userName >> userPass;
  std::string password = bcrypt::generateHash(userPass);

  std::vector<std::string> file = readDataIntoVector("user.csv");
  for (size_t i{0}; i < file.size(); i += 2) {
    if (userName == file[i]) {
      std::cout << "The username (" << userName << ") already exists!\n";
      userExist = true;
    }
  }
  if (!userExist) {
    std::cout << "[Success] Your account has been created!\n";
    std::cout << "Your Username is: " << userName << "\nYour Password is: " << userPass << "\n";
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
  }
  //std::cout << "correct validation " << userPass << " : " << bcrypt::validatePassword(userPass,password) << std::endl;
  //std::cout << "wrong validation : " << bcrypt::validatePassword("666",password) << std::endl;
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
      std::cout << iName << " already exists in the database. Adding (" << iQuantity << ") " << iName 
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
      std::cout << "Deleted (" << iName << ") from the database.\n";
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
    std::cout << "[Failed] attempt at deleting an item that does not exist in item!\n";
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
        std::cout << "Withdrew [Failed]. You tried to withdraw (" << withdrawAmount << ") " << iName << " from the store.\n";
        std::cout << "There's (" << vec[i + 2] << ") " << iName << " left in the store.";
      }
      else {
        std::cout << "Withdrawing (" << withdrawAmount << ") " << iName << " from the store\n";
        vec[i + 2] = std::to_string(std::stoi(vec[i + 2]) - withdrawAmount);
        std::cout << "You have (" << vec[i + 2] << ") " << iName << " left in the store.\n";
        myFile.open("item.csv", std::ios::out);
        for (size_t i{0}; i < vec.size(); i++) {
          myFile << vec[i];
          if (i < vec.size() - i)
            myFile << ",";
        }
        myFile.close();
        break;
      }
    }
  }
}

void invManage::userOptionMenu() {
  short int userInput;
  std::string itemName, itemCategory;
  int itemQuantity;
  std::cout << "Option 1: \n";
  std::cout << "Option 2: \n";
  std::cout << "Option 3: Add an item \n";
  std::cout << "Option 4: Delete an item\n";
  std::cout << "Option 5: Withdraw an item\n";
  std::cout << "Option 6: Search for an item\n";
  std::cout << "Option 7: Display all items\n";
  std::cout << "Option 8: Display by category\n";

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
    case 4: {
      std::cout << "Input (1)ItemName to be deleted from the list\n";
      std::cin >> itemName;
      deleteItem(itemName);
      break;
    }

    case 5: {
      std::cout << "Input (1)ItemName (2)ItemQuantity to withdraw\n";
      std::cin >> itemName >> itemQuantity;
      withdrawItem(itemName, itemQuantity);
      break;
    }

    case 6: {
      std::cout << "Input (1)ItemName to start searching\n";
      std::cin >> itemName;
      searchItem(itemName);
    }

    case 7: {
      display();
    }

    case 8: {
      std::cout << "Input (1)Category Name to start displaying\n";
      std::cin >> itemCategory;
      displayCategory(itemCategory);
    }
  }
}

void invManage::searchItem(std::string iName) {
  bool itemFound = false;
  int width = 10;
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
      std::cout << "\n\n====Item Found====\nItemName |" << std::setw(width) << " Category |" << std::setw(width) << " Quantity\n"
                << iName << std::setw(width+2) << vec[i + 1] << std::setw(width+1) << vec[i + 2] << "\n";
    }
  }
  if (!itemFound)
    std::cout << "Did not find (" << iName << ") in the store.\n";
}

void invManage::display() {
  std::vector<std::string> vec;
  std::fstream myFile;
  myFile.open("item.csv", std::ios::in);
  std::string line;
  while (getline(myFile, line, ',')){
    vec.push_back(line);
  }
  myFile.close();

  std::cout << "Name |" << std::setw(10) << " Category |" << std::setw(10) << " Quantity\n";
  for (size_t i{0}; i < vec.size(); i += 3) {
    std::cout << vec[i] << " | " << vec[i+1] << " | " << vec[i+2] << "\n";
  }
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
  std::cout << "Name |" << std::setw(10) << " Category |" << std::setw(10) << " Quantity\n";
  for (size_t i{0}; i < vec.size(); i += 3) {
    if (iCategory == vec[i+1])
      std::cout << vec[i] << " | " << vec[i+1] << " | " << vec[i+2] << "\n";
  }
}
