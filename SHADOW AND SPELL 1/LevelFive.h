int LevelFive(int damage, int plyrHlth) // this UDF serves to keep all the code for level 1 separate from main for concise
{               // Opens UDF
    int enemyHlth = 200, tempPoints, input;         // declares health points and damage points, as well as an input. Healths will remain up to 100
    plyrHlth = 200;                                 // sets health to 200
	int hlthPotion = 10;                            // the number of potions the player has throughout the story
    this_thread::sleep_for(chrono::seconds(4));     // this delays the print of text to help the player read properly what is on the screen
	cout << "\nZahthorn:(evil grouls). Having the ability to stand in front of me is hilarious."
         << " You must be reckless or a coward. You must also be the hero who I killed your family, \nI guess you enjoyed a happy life being alone."                              // dialogue
         << " Now, I am heading to kill your king and put the kingdom to pure rubbish and ash, \nI love to see the face of everyone crying and begging for salvation to come."  // dialogue
         << " I will enslave everyone and bring misery to this world. Now, prove your worth, Hero!" << endl;  // Prints the enemy's dialogue

	while (plyrHlth != 0 or enemyHlth != 0)    // a while loop will loop as long as any health are not 0
    {                                          // opens loop
        repeat:                                // this goto lander helps go back to the enemy's turn after the player takes a potion, the potion will take up the player's turn.
        this_thread::sleep_for(chrono::seconds(2));                                              // this delays the print of text to help the player read properly what is on the screen
        cout << "\n###################################################################" << endl; // separator for text between player and enemy
        cout << "Player Health: " << plyrHlth << " | Zahthorn Health: " << enemyHlth << endl;    // prints both player's and enemy's health
        cout << "Zahthorn deals ";                                                               // this prints the enemy deals
        tempPoints = rand() % 35 + 25;                                                           // a temporary points is initialized to a rand() statement to determine how much damage has the player received
        cout << tempPoints << " damage points to player!" << endl;                               // finishes the sentence stating the amount of damage points
        plyrHlth -= tempPoints;                                                                  // subtracts player's health with damage, it updates the health
        cout << "###################################################################" << endl;   // separator for text between player and enemy

        this_thread::sleep_for(chrono::seconds(2));                                             // this delays the print of text to help the player read properly what is on the screen
        turn:                                                                                   // this lander serves to go back if the player defends
        cout << "Player Health: " << plyrHlth << " | Zahthorn Health: " << enemyHlth << endl;   // prints both player's and enemy's health
        cout << "\nPlayer's turn..." << endl;                                                   // states it is the player's turn
        cout << "1) Attack" << "\n2) Defend" << "\n3) Heal" << endl;                            // prints options
        cout << "Input here: ";                                                                 // asks to input
        cin >> input;                                                                           // allows user to input an option

        if (input == 1)                                                 // and if statement for attack
        {                                                               // opens statement
            cout << "Player deals " << damage * 2 << " damage points to enemy!" << endl;  // depending on the player's weapon, it will print how many points have been dealt to the enemy
            enemyHlth -= damage * 2;                                    // subtracts enemy's health with damage taken and updates it
            if (plyrHlth <= 0)                                          // this checks to see if player has died
            {                                                           // opens statement
                cout << "Player loses the battle... retrying!" << endl; // prints player lost and will automatically retry
                this_thread::sleep_for(chrono::seconds(4));             // this delays the print of text to help the player read properly what is on the screen
                plyrHlth = 100;                                         // resets health
            }                                                           // closes statement

            else if (enemyHlth <= 0)                                                                             // checks whether enemy died
            {                                                                                                    // opens statement
                cout << "Zahthorn: You have defeated me. I want you all rot and decay, but soon, a greater evil will arrive. \nGo enjoy your pesky lives for now." << endl;  // prints a death dialogue for enemy
                this_thread::sleep_for(chrono::seconds(4));                                                        // this delays the print of text to help the player read properly what is on the screen
                cout << "\nPlayer wins the battle! Health is restored to max!" << endl;                            // prints that the enemy died and player wins, restoring health
                plyrHlth = 100;                                         // restores health to max
                break;                                                  // ends UDF right away
            }                                                           // closes statement
        }                                                               // closes statement

        else if (input == 2)                              // an else if for defending
        {                                                 // opens statement
            int temp = rand() % 2;                        // stores a random value
            if (temp == 0)                                // determines if the player gets to block or receive less damage
            {                                             // opens statement
                cout << "Player blocks attack!" << endl;  // if option 2, player will defend and prints it blocks attack, game is lenient and player gets another turn
                goto turn;                                // after blocking, it uses a goto to return to the player's prompt
            }                                             // closes statement

            else if (temp == 1)                                                         // if 1, player receives half damage
            {                                                                           // opens statement
                cout << "Player receives half damage when trying to block!" << endl;    // prints message
                plyrHlth -= tempPoints / 2;                                             // subtracts damage
                goto turn;                                                              // returns to turn
            }                                                                           // closes statement
        }                                                      // closes statement

        else if (input == 3)                                   // a third else if for healing
        {                                                      // opens statement
            if (hlthPotion == 0)                               // checks whether the player has healing potions, if zero, then execute
            {                                                  // opens statement
                cout << "No health potions left..." << endl;   // if zero, print there are no more potions available
                goto turn;                                     // returns player to their turn
            }                                                  // closes statement
            else // otherwise, execute
            {    // opens statement
               cout << "Player heals with 25 health points!" << endl; // prints player
               plyrHlth += 25;                                        // restores 25 health points
               hlthPotion--;                                          // removes a health potion from inventory
               goto repeat;                                           // this consumes the player's turn and return to the enemy's turn
            }   // closes statement
        }   // closes statement
    }   // closes loop
}   // closes UDF
