/**********************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Member functions of IsleOfFaces class
**********************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "Space.hpp"
#include "IsleOfFaces.hpp"
#include "intValidationRange.hpp"

/*********************************************************
 * Description: Constructor for IsleOfFaces
*********************************************************/
IsleOfFaces::IsleOfFaces()
{
	roomVisited = false; 
}

/*********************************************************
 * Description: Destructor
*********************************************************/
IsleOfFaces::~IsleOfFaces()
{

}

/********************************************************
 * Description: Events that occur once player enters
********************************************************/
void IsleOfFaces::enterRoom(Space* currentRoom, std::vector<std::string>* inventory, int& moves)
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
		
			std::cout << "\n\nYou have arrived to the Isle of Faces, where your vision brought you\n"
				  << "This is where the children of the forest and the first men signed the pact, ages ago\n"
				  << "You see a cave and decide to enter it, theres pictures on that wall!"
				  << "\nAppears to be some sort of battle against white figures with blue eyes..."
				  << "\nYou see a recently moved stone in front of you. Turn it over?\n\n1. Yes\n2. No\n";
			userChoice = intValidationRange(1,2);	
			
			if(userChoice == 1)
			{
				std::cout << "\nA sentence in the common tongue is written on the bottom!\nIt says 'To receive the dragonglass speak Valar Morghulis'\n"
				          << "You will need the dragonglass to defeat the great other!\n"
				          << "Better go to dragonstone and remember 'Valar Morghulis'\n\n";
			}
			else
			{
				std::cout << "\nAre you sure?  Didn't you come to the Isle of Faces to learn something?\n\n1. Turn Stone\n2. Leave\n";
				userChoice = intValidationRange(1,2);
				if(userChoice == 1)
				{
					std::cout << "\nA sentence in the common tongue is written on the bottom!\nIt says 'To receive the dragonglass speak Valar Morghulis'\n"
					          << "You will need the dragonglass to defeat the great other!\n"
					          << "Better go to dragonstone and remember 'Valar Morghulis'\n\n";
				}
				else
				{
					std::cout << "\nYou're probably right, just a waste of time.  Anyways time to leave the Isle of Faces!\n";
				}
			}
			
			// Give user ability to travel between spaces
			std::cout << "You can either travel north to Dragonstone or south to King's Landing.\n"
				  << "1. North (Dragonstone)\n2. South (King's Landing)\n3. Exit\n";
			userChoice = intValidationRange(1,3);
	
			// Go up and enter the room
			if(userChoice == 1)
			{
				currentRoom = currentRoom->getTop();
				currentRoom->enterRoom(currentRoom, inventory, moves);
			}
			// Go down and enter the room
			else if(userChoice == 2)
			{
				currentRoom = currentRoom->getBottom();
				currentRoom->enterRoom(currentRoom, inventory, moves);
			}
			// Exit game
			else
			{
			}
		}
		else
		{
			std::cout << "\n\nWelcome back to the storied Isle Of Faces!\n";
			
			// Give user ability to travel between spaces
			std::cout << "You can either travel north to Dragonstone or south to King's Landing.\n"
				  << "1. North (Dragonstone)\n2. South (King's Landing)\n3. Exit\n";
			userChoice = intValidationRange(1,3);
	
			// Go up and enter the room
			if(userChoice == 1)
			{
				currentRoom = currentRoom->getTop();
				currentRoom->enterRoom(currentRoom, inventory, moves);
			}
			// Go down and enter the room
			else if(userChoice == 2)
			{
				currentRoom = currentRoom->getBottom();
				currentRoom->enterRoom(currentRoom, inventory, moves);
			}
			// Exit game
			else
			{
			}
		}
	}
	else
	{
		std::cout << "\n\n\nYou have ran out of moves without defeating the Great Other!\n\nGOODBYE\n\n";
	}
}
