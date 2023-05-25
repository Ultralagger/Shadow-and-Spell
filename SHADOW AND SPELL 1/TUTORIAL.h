void Tutorial() // UDF is made to store the code for the tutorial
{   // opens UDF
	int selection;  // an integer is declared to store an option
    double plyrHlth = 100.0, skeleton = 25.0, eSword = 15.0, pSword = 25.0; // declares and initializes health points
	cout << "\nWelcome to this tutorial. Here you'll learn the basics of the game.\n"                                                                                           // prints tutorial message
         << "First, this is a turn based game where you choose an action and after giving your turn, the enemy will be next and you must wait until you are asked to input.\n"  // prints tutorial message
         << "Choices will be printed on-screen and you must type the number of what you wish to do. Here is an enemy skeleton wielding a sword\n"                               // prints tutorial message
         << "Your health and the enemy's health will be printed below on top of the selection menu." << endl;                                                                   // prints tutorial message
	cout << "\n###################################################################" << endl;        // message separator
	cout << "Player Health: " << plyrHlth << " | Skeleton Health: " << skeleton << endl;            // prints player and enemy's health
    
	while (plyrHlth != 0 and skeleton != 0)                                                     // a while loop that loops until healths are zero
	{                                                                                           // opens loop  
		cout << "Skeleton uses sword and deals 15 damage points to player!" << endl;            // action prints message
		cout << "###################################################################" << endl;  // message separator
		plyrHlth -= eSword;                                                                     // subtracts and updates player health

		turn:   // a lander if player defends

		cout << "\nPlayer Health: " << plyrHlth << " | Skeleton Health: " << skeleton << endl;  // prints player and enemy's health
		cout << "\nPlayer's turn! Select your action: \n"                                       // tells user its their turn and to select
			 << "1) Attack\n" << "2) Defend\n" << "Input here: ";                               // prints selection
		cin >> selection;                                                                       // allows input of selection

		if (selection == 1)                                                                     // if option 1 for attack, execute
		{                                                                                       // opens statement
			cout << "\nPlayer uses fire blade and deals 25 damage points to skeleton!" << endl; // prints what the player did and how much damage it dealt
			skeleton -= pSword;                                                                 // updates enemy's health
			if (skeleton == 0)  // checks if enemy is dead
			{                   // opens statement
				cout << "\nPLAYER WINS!" << "\nThis concludes our tutorial, you now understand the basic mechanics of the game. You can now begin your journey!" << endl;           // prints tutorial conclusion
				cout << "Please know that defending will block an attack and will return your turn. In the start, you will begin with 10 health potions, use them wisely" << endl; // prints additional tutorial message
				break;  // ends loop
			}           // ends statement
		}               // ends statement

		else if (selection == 2)                                                                    // if defend, execute instead
		{                                                                                           // opens statement
			cout << "Player dodges an attack, skeleton deals 0 damage points to player!" << endl;   // prints defend message
			goto turn;                                                                              // returns user to their turn
		}                                                                                           // ends statement
	}                                                                                               // ends loop
}   // ends loop
