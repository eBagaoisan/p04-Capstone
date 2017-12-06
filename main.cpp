#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{   
    

    //-------------------------------------------------------

    //Player inventory
    string item;
    ofstream ofs;
    ofs.open("inventory.txt");
    cout<<"Enter: ";
    cin>>item;
    ofs<<item;
    ofs.close();
    
    return 0;
}
