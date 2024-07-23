#ifndef INVENTORYMANAGEMENT
#define INVENTORYMANAGEMENT

#include <string>
#include <vector>
#include <unordered_map>

class invManage
{
private:
public:
  std::string userName;
  std::string userPass;

  struct Item 
  {
    std::string itemName;
    std::string itemCategory;
    int itemQuantity;
    Item(std::string name, std::string category, int quanitty);
  };

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
  void populate_stock();
  std::vector<std::string> readDataIntoVectorUser(std::string);
  std::vector<Item> readDataIntoVector(std::string);
  std::unordered_map<std::string, std::vector<Item>> readDataIntoMap(std::string fileName);
};



#endif // !INVENTORYMANAGEMENT
