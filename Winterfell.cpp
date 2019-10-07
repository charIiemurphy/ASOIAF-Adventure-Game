/**********************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Member functions of Winterfell class
**********************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "Space.hpp"
#include "Winterfell.hpp"

#include "intValidationRange.hpp"
/*********************************************************
 * Description: Constructor for Winterfell
*********************************************************/
Winterfell::Winterfell()
{
	roomVisited = false; 
}

/*********************************************************
 * Description: Destructor
*********************************************************/
Winterfell::~Winterfell()
{

}

/********************************************************
 * Description: Events that occur once player enters
********************************************************/
void Winterfell::enterRoom(Space* currentRoom, std::vector<std::string>* inventory, int& moves)
{
	// Decrements moves counter
	moves--;
	int userChoice;
	// If user hasn't used all 10 moves
	if(moves > 0)
	{
		// If first time visiting room
		if(!roomVisited)
		{
			// Set roomVisited to true once user enters room first time
			setRoomVisited(true);
			std::cout << "\n\nWelcome to Winterfell, castle of House Stark\nLast stop before reaching castle black and crossing the wall\n"
				  << "Getting ever closer to the Great Other and an opportunity to save your family and the realm.\n"
				  << "By the old gods and new you can't possibly be trying to go north without a jacket!\n"
				  << "*Jacket added to inventory*\n\n";	
			inventory->push_back("jacket");
		
			std::cout << "Would you like to travel to North of the Wall or South to The Twins\n"
				  << "1. North (North of the Wall)\n2. The Twins\n3. Exit\n";
			userChoice = intValidationRange(1,3);
		
			// User chooses to go north of the wall
			if(userChoice == 1)
			{
				// Enter next room
				currentRoom = currentRoom->getTop();
				currentRoom->enterRoom(currentRoom, inventory, moves);
			}
			else if(userChoice == 2)
			{
				// Enter next room
				currentRoom = currentRoom->getBottom();
				currentRoom->enterRoom(currentRoom, inventory, moves);
			}
			else
			{
			}
		}
		// Been to room and already got jacket
		else 
		{	
			std::cout << "\n\nWelcome back to Winterfell!\n\n";
		
			std::cout << "Would you like to travel north of the wall or south to The Twins?\n"
				  << "1. North of the Wall\n2. The Twins\n3. Exit\n";
			userChoice = intValidationRange(1,3);
				
			if(userChoice == 1)
			{
				currentRoom = currentRoom->getTop();
				currentRoom->enterRoom(currentRoom, inventory, moves);
			}
			if(userChoice == 2)
			{
				currentRoom = currentRoom->getBottom();
				currentRoom->enterRoom(currentRoom, inventory, moves);
			}
			else
			{
			}
			
		}
	}
	else
	{
		std::cout << "\n\n\nYou have used all your moves without defeating the Great Other!\n\nGOODBYE\n\n";
	}
}
