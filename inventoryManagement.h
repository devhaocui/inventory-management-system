#ifndef INVENTORYMANAGEMENT
#define INVENTORYMANAGEMENT

#include <iostream>
#include <string>
#include <fstream>
#include <tuple>
#include <vector>

class invManage{
private:
  std::string userName;
  std::string userPass;
public:
  //void userCreateMenu();
  //void userLoginMenu();
  bool isNumber(std::string item);
  void userOptionMenu();
  void addItem (std::string iName, std::string iCategory, int iQuantity);
  void deleteItem (std::string iName);
  bool categoryExists (std::string iCategory);
  bool itemExists(std::string iName);
  void displayItem ();
  void displayByName();
  void displayByCategory();
  void displayByQuantity();
};



#endif // !INVENTORYMANAGEMENT
