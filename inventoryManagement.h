#ifndef INVENTORYMANAGEMENT
#define INVENTORYMANAGEMENT

#include <string>
#include <vector>

class invManage{
private:
  std::string userName;
  std::string userPass;
public:
  void userCreate();
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
  std::vector<std::string> readDataIntoVector(std::string);
  void writeDataIntoVector(std::vector<std::string>);
};



#endif // !INVENTORYMANAGEMENT
