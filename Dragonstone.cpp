/**********************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Member functions of Dragonstone class
**********************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "Space.hpp"
#include "Dragonstone.hpp"
#include "intValidationRange.hpp"

/*********************************************************
 * Description: Constructor for Dragonstone
*********************************************************/
Dragonstone::Dragonstone()
{
	roomVisited = false;	 
}

/*********************************************************
 * Description: Destructor
*********************************************************/
Dragonstone::~Dragonstone()
{

}

/********************************************************
 * Description: Events that occur once player enters
********************************************************/
void Dragonstone::enterRoom(Space* currentRoom, std::vector<std::string>* inventory, int& moves)
{

	// Decrements moves counter
	moves--;
	int userChoice;
	// If user hasn't used all 10 moves
	if(moves > 0)
	{
		// Sets boolean on if user has Dragongold	
		bool hasDragonglass;
		
		for(int i = 0; i < inventory->size(); i++)
		{
			if(inventory->at(i) == "Dragonglass")
			{
				hasDragonglass = true;
			}
			else
			{
				hasDragonglass = false;
			}
		}


		// If first time visiting room
		if(!roomVisited)
		{
			// Set roomVisited to true once user enters room first time
			setRoomVisited(true);
			userChoice;
			std::cout << "\n\nYour journey has now brought you to Dragonstone, home of Aegon the Conqueror\n"
				  << "There is rumored to be a large amount of dragonglass here, which you believe will help you defeat the others\n"
				  << "There appears to be the outline of a door in a wall of a cave you enteredn\n"
				  << "This might be when to speak the password learned on the Isle of Faces\n\nYou say:\n"
				  << "1. Nuhor lir gurenna\n2. Volar morghulis\n3. Volar dohaerys\n4. Geros ilas\n";
			userChoice = intValidationRange(1,4);

			// 3 is correct answer
			if(userChoice == 2)
			{
				std::cout << "\nA door begins to open in front of you!\nYou enter to see rows and rows of unlimited dragonglass"
					  << "\nYou grab your favorite piece to make a weapon of\n"
					  << "*Dragonglass added to inventory*\n";
				inventory->push_back("Dragonglass");
			}
			else
			{
				std::cout << "\nHmm the door didn't budge\nI will have to try sometime later\n";
			}
		
			std::cout << "You can either travel up to The Twins or down to the Isle of Faces\n"
				  << "1. Up (The Twins)\n2. Down (Isle of Faces)\n3. Exit\n";
			userChoice = intValidationRange(1,3);
		
			// User chooses to go to The Twins
			if(userChoice == 1)
			{
				// Enter next room
				currentRoom = currentRoom->getTop();
				currentRoom->enterRoom(currentRoom, inventory, moves);
			}
			else if(userChoice == 2)
			{
				// Enter bottom room
				currentRoom = currentRoom->getBottom();
				currentRoom->enterRoom(currentRoom, inventory, moves);
			}
			else
			{
			}
		}
		// Been to room
		else 
		{	
			if (roomVisited && hasDragonglass)
			{
				std::cout << "\n\nWelcome back to Dragonstone!\n\n";
		
				std::cout << "You can either travel up to The Twins or down to the Isle of Faces\n"
					  << "1. Up (The Twins)\n2. Isle of Faces\n3. Exit\n";
				userChoice = intValidationRange(1,3);
				
				if(userChoice == 1)
				{
					currentRoom = currentRoom->getTop();
					currentRoom->enterRoom(currentRoom, inventory, moves);
				}
				else if(userChoice == 2)
				{
					// Enter bottom room
					currentRoom = currentRoom->getBottom();
					currentRoom->enterRoom(currentRoom, inventory, moves);
				}
				else
				{
				}
			}
			// Been to room but haven't gotten Dragonglass yet
			else
			{
				std::cout << "\n\nWelcome back to Kings Landing!\nYou have arrived back to door in the cave\n"
					  << "This might be when to speak the password learned on the Isle of Faces\n\nYou say:\n"
					  << "1. Nuhor lir gurenna\n2. Volar morghulis\n3. Volar dohaerys\n4. Geros ilas\n";
				userChoice = intValidationRange(1,4);

				// 3 Is correct answer
				if(userChoice == 2)
				{
					std::cout << "\nA door begins to open in front of you!\nYou enter to see rows and rows of unlimited dragonglass"
						  << "\nYou grab your favorite piece to make a weapon of\n"
						  << "*Dragonglass added to inventory*\n";
					inventory->push_back("Dragonglass");
				}
				else
				{
					std::cout << "\nDoor STILL wont open\nGuess you'll have to try again sometime\n";
				}
			
				std::cout << "You can travel north to The Twins or south to the Isle of Faces\n"
					  << "1. North (The Twins)\n2. South (Isle of Faces)\n3.Exit\n";
				userChoice = intValidationRange(1,3);
			
				// User chooses to travel up
				if(userChoice == 1)
				{
					currentRoom = currentRoom->getTop();
					currentRoom->enterRoom(currentRoom, inventory, moves);
				}
				else if(userChoice == 2)
				{
					// Enter bottom room
					currentRoom = currentRoom->getBottom();
					currentRoom->enterRoom(currentRoom, inventory, moves);
				}
				else
				{
				}
			}
		}
	}
	else
	{
		std::cout << "\n\n\nYou have used all your moves without defeating the Great Other!\n\nGOODBYE\n\n";
	}

}
