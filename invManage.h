#ifndef INVMANAGE
#define INVMANAGE

#include <string>

class invManage{
private:
  std::string userName;
  std::string userPass;
public:
  void userCreateMenu();
  void userLoginMenu();
  void userOptionMenu();
  void addItem (std::string iName, std::string iCategory, int iQuantity);
  bool categoryExists (std::string iCategory);
  bool itemExists(std::string iName);
  void deleteItem (std::string iName);
  void displayItem ();
  void displayByName();
  void displayByCategory();
  void displayByQuantity();
};



#endif // !INVMANAGE
