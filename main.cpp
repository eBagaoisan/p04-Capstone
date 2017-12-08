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

vector<string> inventory;
string interaction;

int main()
{   
    //variables
    bool interact = true;
    string intro;
    string printInventory;
    string partInventory;
    string 

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
         cout<<"You've walked over to the painting."<<endl;
         cout<<"You notice a tear in the canvas..."<<endl;
         cout<<"What would you like to do?\n"<<endl;
         //add code for having/not having Razor; bool == true/false
         
         
    }

    //Boarded Window-----------------------------------------------

    void window()
    {
        cout<<"You've walked over to the boarded up window."<<endl;
        cout<<"You notice a glare on the window sill..."<<endl;
        inventory.push_back("Lock Pick");
        cout<<"\"Lock Pick\" is now in your inventory!"<<endl;
        if (inventory.size()<1)
        {
            cout<<"To access inventory type \"inventory\"."<<endl;
        }
    }

    //Messy Desk---------------------------------------------------

    void messyDesk()
    {
        cout<<"You've walked over to a messy desk."<<endl;
        cout<<"You notice 2 drawers and a mysterious liquid on the desk."<<endl;
        cout<<"Options:(C1)heck drawer 1\n\t(C2)heck drawer 2\n\t(I)nspect Liquid\n\t(E)xit"<<endl;
        cout<<"What would you like to do?"<<endl;
        cin>>interaction;

        if (interaction == "c1" || interaction == "C1")
        {
            cout<<"Drawer is empty..."<<endl;
        }
        //---------------------------------------------------------------
        else if (interaction == "c2" || interaction == "C2")
        {
            cout<<"You've found a Razor Blade!"<<endl;
            inventory.push_back("Razor Blade");
            cout<<"\"Razor Blade\" is now in your inventory!"<<endl;
            if (inventory.size()<1)
            {
                cout<<"To access inventory type \"inventory\"."<<endl;
            }
        }
        //---------------------------------------------------------------
        else if (interaction == "I" || interaction == "i")
        {
            cout<<"You've grabbed the mysterious liquid."<<endl;
            inventory.push_back("Mysterious Liquid");
            cout<<"\"Mysterious Liquid\" is now in your inventory!"<<endl;
            if (inventory.size()<1)
            {
                cout<<"To access inventory type \"inventory\"."<<endl;
            }
        }
        //---------------------------------------------------------------
        else if (interaction == "e" || interaction == "E")
        {
            cout<<"You've left the messy desk."<<endl;
        }
        else
        {
            cout<<"Invalid input, try again..."<<endl;
        }
    }

    //Door 1-------------------------------------------------------

    void door1()
    {
        cout<<"You've walked over to the door."<<endl;
        //input code to check inventory, if item is in inventory; bool = true
        cout<<"Options:(O)pen door
        cout<<"What would you like to do?"
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
