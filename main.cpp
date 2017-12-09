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
bool door1();

Inventory playerInventory; //creates players inventory to hold pick ups
string interaction;
vector<string> userPrint; //prints player current inventory
bool unlock1 = true; //Checks if door1 is unlocked, if not then run 1st room loop

int main()
{   
    //variables
    bool interact = true;
    string intro;
    string printInventory;
    string partInventory;

//Intro----------------------------------------------------------------------------
    
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

//Object Interaction---------------------------------------------------------------
    bool room1 = true;

    cout<<"Enter the following to interact..."<<endl;
    while (room1 == true)
    {
        cout<<"\"W\" = Odd painting"<<endl;
        cout<<"\"A\" = Boarded Up Window"<<endl;
        cout<<"\"S\" = Messy Desk"<<endl;
        cout<<"\"D\" = Door"<<endl;
        
        if(playerInventory.getSize() > 1)
        {
            cout<<"\"Inventory\" = Check Inventory"<<endl;
        }

        cin>>interaction;
        cout<<endl;
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
            room1 = unlock1;
        }
        else if (interaction == "Inventory" || interaction == "inventory")
        {
        //INVENTORY.TXT--------------------------------------------------------------
            ifstream ifs;
            ifs.open("inventory.txt");
            while(!ifs.eof())
            {
                getline(ifs,partInventory);
                printInventory += partInventory + "\n"; 

            }
            ifs.close();
            cout<<printInventory;
        //--------------------------------------------------------------------------

            userPrint = playerInventory.getInventory();
            for (int r = 0; r<playerInventory.getSize(); r++)
            {
                cout<<"-"<<userPrint[r]<<endl;
            }
            cout<<endl;
        }
    }
    return 0;
}

//Odd Painting----------------------------------------------------------------------

    void oddPainting()
    {
        bool exitPainting = false;
        bool cutCanvas = false;
        bool razorBlade = false;

        cout<<"You've walked over to the painting."<<endl;
        cout<<"You notice a tear in the canvas..."<<endl;
        cout<<"What would you like to do?\n"<<endl;
        for (int r = 0; r<playerInventory.getSize(); r++)
        {
            if (playerInventory.getItem("Razor Blade") == true)
            {
                razorBlade = true;
            }
        }
        //---------------------------------------------------------
        while(exitPainting == false)
        {
            if (razorBlade == true)
            {
                cout<<"Options:(T)ear canvas\n\t(C)ut through the Canvas\n\t(E)xit";
            }
            else
            {
                cout<<"Options:(T)ear canvas\n\t(E)xit";
            }
            cout<<endl;
            cin>>interaction;
            cout<<endl;
        //---------------------------------------------------------
            if (interaction == "t" || interaction == "T")
            {
                cout<<"You try to tear away at the canvas."<<endl;
                cout<<"Canvas gives a little bit but won't rip any longer..."<<endl;
            }
            else if (interaction == "c" || interaction == "C")
            {
                if (cutCanvas == false)
                {
                    cout<<"You use the Razor Blade you found earlier to cut away at the canvas."<<endl;
                    cutCanvas = true;
                }
                cout<<"Underneath the canvas you notice a riddle...\n"<<endl;
                cout<<"Take the Roman Numeral of 4, if you add a symbol, what number is spelled?"<<endl;
                cin>>interaction;
                if (interaction == "Six" || interaction == "six" || interaction == "SiX" || interaction == "sIX" || interaction == "SIx")
                {
                    cout<<"Take note number 6..."<<endl;
                    playerInventory.addItem("Note of 6");
                    cout<<"\"Note of 6\" has been added to your inventory!"<<endl;
                    cout<<endl;
               }
                else
                {
                    cout<<"Hmm... "<<interaction<<" doesn't seem quite right."<<endl;
                }
            }   
            else if (interaction == "e" || interaction == "E")
            {
                cout<<"You've left the painting."<<endl;
                exitPainting = true;
            }
            else
            {
                cout<<"Invalid entry, try again."<<endl;
            }
        }

           
    }

//Boarded Window-------------------------------------------------------------------

    void window()
    {
        cout<<"You've walked over to the boarded up window."<<endl;
        cout<<"You notice a glare on the window sill..."<<endl;
        
        playerInventory.addItem("Lock Pick");
        
        cout<<"\"Lock Pick\" is now in your inventory!"<<endl;
        if (playerInventory.getSize()<2)
        {
            cout<<"To access inventory type \"inventory\"."<<endl;
        }
        cout<<endl;
    }

//Messy Desk-----------------------------------------------------------------------
    //code loop until (E)xit is entered
    void messyDesk()
    {
        bool exitDesk = false;

        cout<<"You've walked over to a messy desk."<<endl;
        cout<<"You notice 2 drawers and a mysterious liquid on the desk."<<endl;

        while(exitDesk == false)
        {
            cout<<"Options:(C1)heck drawer 1\n\t(C2)heck drawer 2\n\t(I)nspect Liquid\n\t(E)xit"<<endl;
            cout<<"What would you like to do?"<<endl;
            cin>>interaction;
            cout<<endl;
        
            if (interaction == "c1" || interaction == "C1")
            {
                cout<<"Drawer is empty..."<<endl;
            }
        //---------------------------------------------------------------
            else if (interaction == "c2" || interaction == "C2")
            {
                cout<<"You've found a Razor Blade!"<<endl;
                playerInventory.addItem("Razor Blade");
                cout<<"\"Razor Blade\" is now in your inventory!"<<endl;
                cout<<endl;
                if (playerInventory.getSize()<2)
                {
                    cout<<"To access inventory type \"inventory\"."<<endl;
                }
            }   
        //---------------------------------------------------------------
            else if (interaction == "I" || interaction == "i")
            {
                cout<<"You've grabbed the mysterious liquid."<<endl;
                playerInventory.addItem("Mysterious Liquid");
                cout<<"\"Mysterious Liquid\" is now in your inventory!"<<endl;
                if (playerInventory.getSize()<2)
                {
                    cout<<"To access inventory type \"inventory\"."<<endl;
                }
            }   
        //---------------------------------------------------------------
            else if (interaction == "e" || interaction == "E")
            {
                cout<<"You've left the messy desk."<<endl;
                exitDesk = true;
            }
            else
            {
                cout<<"Invalid input, try again..."<<endl;
            }
         }
    }

//Door 1------------------------------------------------------------------------------
bool door1Key = false;
    bool door1()
    {
        bool lockPick = false;
        bool exitDoor = false;
        bool num6 = false;

        cout<<"You've walked over to the door."<<endl;
        //input code to check inventory, if item is in inventory; bool = true
        for (int r = 0; r < playerInventory.getSize(); r++)
        {
            if (playerInventory.getItem("Lock Pick") == true)
            {
                lockPick = true;
            }
            if (playerInventory.getItem("Note of 6") == true)
            {
                num6 = true;
            }
        }
        while (exitDoor == false)
        {
            if (lockPick == true)
            {
                cout<<"Options:(O)pen door\n\t(P)ick Lock\n\t(E)xit"<<endl;
            }
            else
            {
                cout<<"Options:(O)pen door\n\t(E)xit"<<endl;
            }

            cout<<"What would you like to do?"<<endl;
            cin>>interaction;

            if(interaction == "o" || interaction == "O")
            {
                cout<<"The door won't budge..."<<endl;
                cout<<"You inspect the lock to be loose and further notice a single pin keypad."<<endl;
            }
            else if (interaction == "p" || interaction == "P")
            {
                if (door1Key == false)
                {
                cout<<"Attempted to use the Lockpick to loosen the lock"<<endl;
                }
                door1Key == true;
                if (num6 == true)
                {   
                    cout<<"You enter \"6\" into the number pad...\n"<<endl;
                    cout<<"The door is unlocked..."<<endl;
//END GAME-----------------------------------------------------------------------------                    
                    cout<<"CONGRADUALTIONS YOU ESCAPED THE ROOM!"<<endl;
                    unlock1 = false;
                    exitDoor = true;
                }
                else
                {
                    cout<<"You need a pin number to proceed..."<<endl;
                }
            }
            else if (interaction == "e" || interaction == "E")
            {
                cout<<"You've left the door"<<endl;
                cout<<endl;
                exitDoor = true;
            }
            else
            {
                cout<<"Invalid input, try again...\n"<<endl;
            }
        }
        return unlock1;
    }
