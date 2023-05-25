#include <iostream>   // allows the input and output of info
#include <fstream>    // allows the read and write of files
#include <chrono>     // this allows the delay of reading lines of code
#include <thread>     // a chrono helper to identify what to delay
#include <vector>     // creates vectors
using namespace std;  // saves time writing std::
#include "TUTORIAL.h" // the tutorial is saved in a separate file to keep the code concise
#include "PROLOGUE.h" // the prologue is saved in a separate file to keep the code concise
#include "LevelOne.h" // calls in the level 1 code and it is written in a .h file to keep the code consice
#include "LevelTwo.h" // calls in the level 2 code and it is written in a .h file to keep the code consice
#include "LevelThree.h" // calls in the level 3 code and it is written in a .h file to keep the code consice
#include "LevelFour.h"  // calls in the level 4 code and it is written in a .h file to keep the code consice
#include "LevelFive.h"  // calls in the level 5 code and it is written in a .h file to keep the code consice

int characterSelection(int damage)    // a UDF for character selection
{   // opens UDF
    int select, holder;                                    // an integer made to store a selection
    vector<int> damages = {35, 34, 32, 30, 34};            // a vector that houses all damage values
    cout << "\nPlease choose your character!" << endl;     // prints message to ask to choose a character
    cout << "1) Knight (35 damage points)"                 // prints selection
         << "\n2) Elf Archer (34 damage points)"           // prints selection
         << "\n3) Dwarf (32 damage points)"                // prints selection
         << "\n4) Wizard (30 damage points)"               // prints selection
         << "\n5) Gladiator (34 damage points)" << endl;   // prints selection
    cout << "Input here: ";
    cin >> select;  // inputs selection

    for (int i = 0; i < damages.size(); i++)   // a for loop to go through the vector
    {                                          // opens loop
        if (i == select - 1)    // if the selection - 1 is the same number as i, execute the statement
        {                       // opens statement
            damage = damages[i];// return the value at i in the vector
            break;              // ends loop
        }                       // closes statement
    }               // closes loop
    return damage;  // returns the selected damage value
}                   // closes UDF

int main()                                    // the famous int main where most code happens
{                                             // opens main
	ifstream reader;                          // an ifstream to read a save
	ofstream saver;                           // an ofstream to write a save
	int option, count = 0, state, damage = 0; // declares this integer for selection, count, and a save state
	int plyrHlth = 100;                       // declares and initializes player health
	menu:                                     // this lander helps return the user after the tutorial
	cout << "\nWelcome to SHADOW AND SPELL." << "\n1) New Game" << "\n2) Continue" << "\n3) How To Play" << "\n4) Exit" << "\nPlease input your choice here: ";  // prints a list of options and the greeting
	cin >> option;  // allows user to input desired option

	switch (option)	                       // switch cases
	{					                   // opens switch
		case 1:			                   // case 1 if player selects new game
		    damage = characterSelection(damage); // calls a UDF and returns and stores a value
			Prologue();                    // sends user to a UDF to print the dialogue
        	count++;	                   // count level progress
        	saver.open("save.txt");        // opens save file
            saver << count;                // writes current level
            saver.close();                 // closes file
        	checkpointOne:                 // lander if reader finds there is a save at level 1
        	plyrHlth = LevelOne(damage, plyrHlth);    // sends user to level one if starts new game, continues, or selects level.
            goto lander;                   // this serves to jump the user to the next stages after

        case 2:			 				// case 2 if continue
            reader.open("save.txt");	// opens a file to read save state
            reader >> state;            // stores the save value

			if (state == 1)			    // checks if empty or not
			{							// opens statement
			    goto checkpointOne;     // sends player to latest state
			}							// closes statement

			else if (state == 2)	    // checks if empty or not
			{							// opens statement
			    goto checkpointTwo;     // sends player to latest state
			}							// closes statement

			else if (state == 3)	    // checks if empty or not
			{							// opens statement
			    goto checkpointThree;   // sends player to latest state
			}							// closes statement

			else if (state == 4)	    // checks if empty or not
			{							// opens statement
			    goto checkpointFour;    // sends player to latest state
			}							// closes statement

			else if (state == 5)	    // checks if empty or not
			{							// opens statement
			    goto checkpointFive;    // sends player to latest state
			}							// closes statement

			else 										// otherwise, false
			{											// opens statement
                cout << "No save state found." << endl; // if no save state, print message
				goto menu;								// returns user to menu
			}											// closes statement

		case 3:				// case 3 if
			Tutorial();     // sends user to the tutorial
			goto menu;      // after tutorial is over, return user to main menu

		case 4:		  // case 4 if exit
			return 0; // ends program
	}                 // closes switch

	lander: // after level one, this helps get out of the switch and move on to next level
    //---------------------------------------------------------------------------------------------------
    // LEVEL 2
    cout << "\nProgress map: X ---- O ---- # ---- # ---- BOSS" << endl; // prints the progress map of the user after beating a level
    count++;    // counts level progress to save

    saver.open("save.txt"); // opens save file
    saver << count;         // writes current level
    saver.close();          // closes file

    cout << "\nDo you wish to continue? progress has been automatically saved" << "\n1) Next nevel" << "\n2) Main menu" << "\n Input here:";	// asks player if they want to continue the game or go back to main menu
    cin >> option;	// user inputs here

    if (option == 1)		// if continue or option 1, execute
    {						// opens statement
    	checkpointTwo:      // lander if reader finds there is a save at level 2
        cout << "\nOur hero then navigates into the dark forest and encounters a health potion laying next to a bush (can recover 75 health points) \nand decides to store it in their bag."  // DIALOGUR
             << " Because of this, our Hero starts to feel a cold shiver among their body which causes wind \nto form, picking leaves and wood sticks manifesting a barely visible ghoul" << endl;    // DIALOGUE
    	plyrHlth = LevelTwo(damage, plyrHlth);   // sends UDF for next level
	}					    // ends statement

	else if (option >= 2)	// else, execute
	{						// opens statement
		goto menu;			// send to main menu
	}						// ends statement
    //---------------------------------------------------------------------------------------------------
    // LEVEL 3
	cout << "\nProgress map: X ---- X ---- O ---- # ---- BOSS" << endl; // prints the progress map of the user after beating a level
    count++;    // counts level progress to save

    saver.open("save.txt"); // opens save file
    saver << count;         // writes current level
    saver.close();          // closes file

    cout << "\nDo you wish to continue? progress has been automatically saved" << "\n1) Next nevel" << "\n2) Main menu" << "\n Input here:";	// asks player if they want to continue the game or go back to main menu
    cin >> option;	// user inputs here

    if (option == 1)		// if continue or option 1, execute
    {						// opens statement
    	checkpointThree:    // lander if reader finds there is a save at level 3
        cout << "\nAfter this successful battle, the hero ventures towards a cleared, semi-paved road which our hero realizes it is \nthe path that takes to the haunted mansion where the fearsome Jack O Lantern lives."    // DIALOGUE
             << " as the hero passes the mansion with care, \na cat passes by causing the hero to gasp loudly, eventually causing Jack to appear" << endl;    // DIALOGUE
    	plyrHlth = LevelThree(damage, plyrHlth); // sends UDF for next level
	}						// ends statement

	else if (option >= 2)	// else, execute
	{						// opens statement
		goto menu;			// send to main menu
	}						// ends statement
    //---------------------------------------------------------------------------------------------------
	// LEVEL 4
	cout << "\nProgress map: X ---- X ---- X ---- O ---- BOSS" << endl; // prints the progress map of the user after beating a level
    count++;    // counts current level to save

    saver.open("save.txt"); // opens save file
    saver << count;         // writes current level
    saver.close();          // closes file

    cout << "\nDo you wish to continue? progress has been automatically saved" << "\n1) Next nevel" << "\n2) Main menu" << "\n Input here:";	// asks player if they want to continue the game or go back to main menu
    cin >> option;	// user inputs here

    if (option == 1)		// if continue or option 1, execute
    {						// opens statement
    	checkpointFour:     // lander if reader finds there is a save at level 4
        cout << "\nOnce the Jack was defeated, the evil Zahthorn is seen clearly, roaring, and spewing fire into the sky. Because the hero was closer to the dragon, \nthe sky was now being partially clouded."  // DIALOGUE
             << " As the hero walks, he stops by a small market owned by a trusty gnome who sells our hero protein snacks \nand water for a healthier journey and moves on afterwards."   // DIALOGUE
             << " Suddenly seeing a portal open, seeing a demon come out and face the hero" << endl;    // DIALOGUE
    	plyrHlth = LevelFour(damage, plyrHlth);	// sends UDF for next level
	}						// ends statement

	else if (option >= 2)	// else, execute
	{						// opens statement
		goto menu;			// send to main menu
	}						// ends statement
    //---------------------------------------------------------------------------------------------------
	// LEVEL 5
	cout << "\nProgress map: X ---- X ---- X ---- X ---- BOSS" << endl; // prints the progress map of the user after beating a level
    count++;    // counts level progress to save

    saver.open("save.txt"); // opens save file
    saver << count;         // writes current level
    saver.close();          // closes file

    cout << "\nDo you wish to continue? progress has been automatically saved" << "\n1) Next nevel" << "\n2) Main menu" << "\n Input here:";	// asks player if they want to continue the game or go back to main menu
    cin >> option;	// user inputs here

    if (option == 1)		// if continue or option 1, execute
    {						// opens statement
    	checkpointFive:     // lander if reader finds there is a save at level 5
        cout << "\nAfter the memory that the hero was reminded of, they sit down next to a river, thinking of the moments that traumatized our hero \nwhich lead to the decision of becoming the best hero ever to bring revenge for what happened."  // DIALOGUE
             << " Enraged, he then remembers a faint \nmemory of the mother who told that with great consistency, and the power of enlightment, any enemy will be weak."   // DIALOGUE
             << " \nThis causes the hero to stand up and run towards the awakening area. Moments later, the encounter happens (PLAYER HEALTH TO 200 PERCENT!)" << endl;  // DIALOGUE
    	plyrHlth = LevelFive(damage, plyrHlth);	// sends UDF for next level
	}						// ends statement

	else if (option >= 2)	// else, execute
	{						// opens statement
		goto menu;			// send to main menu
	}						// ends statement
	return 0;	// success indicator
}	// close main
