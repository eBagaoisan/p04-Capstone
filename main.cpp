#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "inventory.h"

using namespace std;

//Prototypes
void oddPainting();
void window();
void messyDesk();
void door1();

int main()
{   
    //variables
    bool interact = true;
    string intro;
    string printInventory;
    string partInventory;

    //Intro-------------------------------------------------------
    
    ifstream introIFS;
    introIFS.open("intro.txt");
    string introPrint;
    while(!introIFS.eof())
    {
        getline(introIFS, intro);
        introPrint += intro + "\n";
    }
    cout<<introPrint;
    introIFS.close();

    //Object Interaction-------------------------------------------
    string interaction;
    bool room1 = true;

    cout<<"Enter the following to interact..."<<endl;
    while (room1 == true)
    {
        cout<<"\"W\" = Odd painting"<<endl;
        cout<<"\"A\" = Boarded Up Window"<<endl;
        cout<<"\"S\" = Messy Desk"<<endl;
        cout<<"\"D\" = Door"<<endl;

        cin>>interaction;
        if (interaction  == "W" || interaction == "w")
        {
            oddPainting();
        }
        else if (interaction == "A" || interaction == "a")
        {
            window();
        }
        else if (interaction == "S" || interaction == "s")
        {
            messyDesk();
        }
        else if (interaction == "D" || interaction == "d")
        {
            door1();
        }
    }
    return 0;
}

    //Odd Painting-------------------------------------------------

    void oddPainting()
    {
        cout<<"its a painting"<<endl;
    }

    //Boarded Window-----------------------------------------------

    void window()
    {
        cout<<"its a boarded window"<<endl;
    }

    //Messy Desk---------------------------------------------------

    void messyDesk()
    {
        cout<<"its a dirty desk"<<endl;
    }

    //Door 1-------------------------------------------------------

    void door1()
    {
        cout<<"its a door"<<endl;
    }

    //Inventory----------------------------------------------------

/*
    //Player inventory
    string item;
    ofstream ofs;
    ofs.open("inventory.txt");
    do
    {
        cout<<"Enter: ";
        getline(cin,item);   //saves multiple words of string.
        ofs<<item<<endl;
    }while(item != "Done");
    ofs.close();
    ifstream ifs;
    ifs.open("inventory.txt");

    while(!ifs.eof())
    {
        getline(ifs,partInventory);
        printInventory += partInventory + "\n"; 

    }
    ifs.close();
    cout<<printInventory;
*/
