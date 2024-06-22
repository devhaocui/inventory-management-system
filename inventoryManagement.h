#ifndef INVENTORYMANAGEMENT
#define INVENTORYMANAGEMENT

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

class invManage{
private:
  std::string userName;
  std::string userPass;
public:
  //void userCreateMenu();
  //void userLoginMenu();
  //bool isNumber(std::string item);
  void userOptionMenu();
  void addItem (std::string, std::string, int);
  void deleteItem (std::string);
  void withdrawItem (std::string, int);
  bool categoryExists (std::string);
  bool itemExists(std::string);
  void searchItem (std::string);
  void display();
  void displayByName (std::string);
  void displayCategory (std::string);
  void displayByQuantity ();
};



#endif // !INVENTORYMANAGEMENT
