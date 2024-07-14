#ifndef INVENTORYMANAGEMENT
#define INVENTORYMANAGEMENT

#include <string>
#include <vector>

class invManage{
private:
public:
  std::string userName;
  std::string userPass;
  bool userCreate();
  void userLogin(std::string, std::string);
  bool userValidate(std::string, std::string);
  void mainMenu();
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
  void tuple_sort();
  void populate_stock();
  std::vector<std::string> readDataIntoVector(std::string);
};



#endif // !INVENTORYMANAGEMENT
