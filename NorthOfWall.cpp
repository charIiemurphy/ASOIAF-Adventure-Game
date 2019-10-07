/**********************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Member functions of NorthOfWall class
**********************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "Space.hpp"
#include "NorthOfWall.hpp"
#include "intValidationRange.hpp"

/*********************************************************
 * Description: Constructor for NorthOfWall
*********************************************************/
NorthOfWall::NorthOfWall()
{
	roomVisited = false; 
}

/*********************************************************
 * Description: Destructor
*********************************************************/
NorthOfWall::~NorthOfWall()
{

}

/********************************************************
 * Description: Events that occur once player enters
********************************************************/
void NorthOfWall::enterRoom(Space* currentRoom, std::vector<std::string>* inventory, int& moves)
{

	// Decrements moves counter
	moves--;
	int userChoice;
	// If user hasn't used all 10 moves
	if(moves > 0)
	{
		// Sets to false then tests if in inventory	
		bool hasDragonglass = false;
	
		if(!inventory->empty())
		{
			for(int i = 0; i < inventory->size(); i++)
			{
				if(inventory->at(i) == "Dragonglass")
				{
					hasDragonglass = true;
				}
			}
		}
			
		std::cout << "\n\nYou have finally crossed the wall and entered the true north.\n"
			  << "Land of the wildings, and their King Mance Raynar.  The land where no man kneels\n"
			  << "Time to begin your trek to find the great other\n"
			  << "You find a large herd of undead, the Great Other emerges to fight you in single combat\n";
			
		if(hasDragonglass)
		{	
			std::cout << "The great other approached and swings his sword!\n1. Parley\n2. Cower\n";
			userChoice = intValidationRange(1,2);
			// Fights back by meeting sword swing
			if(userChoice == 1)
			{
				std::cout << "Parley successful! What next?\n1. Strike Back\n2. Run!\n";
				userChoice = intValidationRange(1,2);
				// Chooses to strike back
				if(userChoice == 1)
				{
					std::cout << "You strike back with the dragonglass and defeat the great other!\n"
						  << "The great enemy of millenia has finally been defeated, by a single person even!\n"
						  << "The realm can finally be safe and you musn't worry about the great danger anymore\n"
						  << "Would you like to return home now?\nOr travel to the lands of Always Winter where no one has ever returned...\n"
						  << "1. Return Home (exit)\n2. Lands of Always Winter\n";
					userChoice = intValidationRange(1,2);
			
					if(userChoice == 2)
					{
					// Enter next room
					currentRoom = currentRoom->getTop();
					currentRoom->enterRoom(currentRoom, inventory, moves);
					}
				}
			}
			// Chose to cower instead of fight
			else
			{
				std::cout << "The great other strikes you dead while you lay there cowering ... good job\n\n";
			}
		}
		// Didn't bring dragonglass
		else
		{
			std::cout << "You didn't bring dragonglass! Uh Oh...\n"
				  << "*Killed by great other\n\nThanks for playing! Always remember your dragonglass!\n";
		}
	}

	else
	{
		std::cout << "\n\n\nYou have used all your moves without defeating the Great Other!\n\nGOODBYE\n\n";
	}
}

