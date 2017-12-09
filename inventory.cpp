#include "inventory.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;



vector<string> Inventory::getInventory()
{
    return inventoryList;
}

int Inventory::getSize()
{
    return inventoryList.size();
}
bool Inventory::getItem(string item)
{
    for (int r = 0; r<inventoryList.size(); r++)
    {
        if (inventoryList[r] == item)
        {
            return true;        
        }
    }
    return false;
}

void Inventory::addItem(string pickUp)
{   
    inventoryList.push_back(pickUp);
}




