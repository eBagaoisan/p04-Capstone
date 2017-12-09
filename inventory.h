#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include <string>
#include <vector>

using namespace std;

class Inventory
{
    private:
      vector<string> inventory;
      vector<string> inventoryList;
      //string item;
    //==============================================
    public:
    vector<string> getInventory();
    int getSize();
    bool getItem(string );
    void addItem(string );

};

#endif
