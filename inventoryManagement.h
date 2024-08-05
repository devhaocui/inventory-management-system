#ifndef INVENTORYMANAGEMENT
#define INVENTORYMANAGEMENT

#include <string>
#include <unordered_map>
#include <vector>

class invManage {
private:
public:
  std::string userName;
  std::string userPass;

  struct Item {
    int itemID;
    std::string itemName;
    std::string itemCategory;
    int itemQuantity;

    // constructor to initialize values
    Item(std::string name, std::string category, int quanitty);
  };

  bool userCreate();
  void userLogin(std::string, std::string);
  bool userValidate(std::string, std::string);
  void mainMenu();
  void userOptionMenu();
  void addItem(std::string, std::string, int);
  void deleteItem(std::string);
  void withdrawItem(std::string, int);
  bool categoryExists(std::string);
  bool itemExists(std::string);
  void searchItem(std::string);
  void populate_stock();
  std::vector<std::string> readDataIntoVectorUser(std::string);
  std::vector<Item> readDataIntoVector(std::string);
  std::unordered_map<std::string, std::vector<Item>>
  readDataIntoMap(std::string fileName);
  int sqltest();
};

#endif // !INVENTORYMANAGEMENT
