/**********************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Member functions of TheTwins class
**********************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Space.hpp"
#include "TheTwins.hpp"
#include "intValidationRange.hpp"

/*********************************************************
 * Description: Constructor for TheTwins
*********************************************************/
TheTwins::TheTwins()
{
	roomVisited = false; 
}

/*********************************************************
 * Description: Destructor
*********************************************************/
TheTwins::~TheTwins()
{

}

/********************************************************
 * Description: Events that occur once player enters
********************************************************/
void TheTwins::enterRoom(Space* currentRoom, std::vector<std::string>* inventory, int& moves)
{

	// Decrements moves counter
	moves--;
	int userChoice;

	// If user hasn't used all 10 moves
	if(moves > 0)
	{
		// Starts of false, will become true if any inventory sports are dragongold
		bool hasDragongold = false;
		
		// Test if any inventory sports are dragongold
		for(int i = 0; i < inventory->size(); i++)
		{
			if(inventory->at(i) == "Dragongold")
			{
				hasDragongold = true;
			}
		}
		// If first time visiting room
		if(!roomVisited)
		{
			// Set roomVisited to true once user enters room first time
			setRoomVisited(true);
			
			std::cout << "\n\nWelcome to the Twins, house of Lord Frey\n"
				  << "Due to it being the only way to cross the trident to get north, they charge everyone a toll\n"
				  << "Hopefully you brough some money with you...\n"
				  << "Hello traveler, to cross The Twins you'll need to pay us a 1 Dragongold toll\n"
				  << "1. Pay Toll\n2. Refuse\n";
			userChoice = intValidationRange(1,2);

			// 3 is correct answer
			if(userChoice == 1)
			{
				if(hasDragongold)
				{
					// To ensure user only has to pay toll one time
					setTollPaid(true);
					std::cout << "\n*You have paid toll and spent 1 Dragoncoin*\n*Dragoncoin removed from inventory*\n"
						  << "You are free to travel north to Winterfell now\n";
				
					std::vector<std::string>::iterator position = std::find(inventory->begin(), inventory->end(), "Dragoncoin");
					if (position != inventory->end()) // == myVector.end() means the element was not found
					{
						inventory->erase(position);
					}

					std::cout << "\n\nWould you like to travel to Winterfell now?\n1. Go to Winterfell\n2. Exit\n";
					userChoice = intValidationRange(1,2);

					if(userChoice == 1)
					{
						// Move user north
						currentRoom = currentRoom->getTop();
						currentRoom->enterRoom(currentRoom, inventory, moves);
					}
				}
				else
				{
					std::cout << "\nNo money!?  Go back to Kings landing where you're from and come back with a Dragoncoin\n\n";
					std::cout << "\nWould you like to travel back south to Dragonstone now?\n1. Go to Dragonstone\n2. Exit\n";
					userChoice = intValidationRange(1,2);

					if(userChoice == 1)
					{
						// Move user south
						currentRoom = currentRoom->getBottom();
						currentRoom->enterRoom(currentRoom, inventory, moves);
					}
				}
			}
			else
			{
				std::cout << "\n\nGood luck trying to find another way up north peasant\n\n";
			}
		}
		// Been to room and already got Dragoncoin
		else 
		{	
			if (roomVisited && tollPaid)
			{
				std::cout << "\n\nWelcome back to The Twins, castle of House Frey!\n\n";
		
				std::cout << "Would you like to travel north to Winterfell or south to Dragonstone\n"
					  << "1. North (Winterfell)\n2. South (Dragonstone)\n3. Exit\n";
				userChoice = intValidationRange(1,3);
				
				if(userChoice == 1)
				{
					currentRoom = currentRoom->getTop();
				}
				else if(userChoice == 2)
				{
					currentRoom = currentRoom->getBottom();
				}
				else
				{
				}
				currentRoom->enterRoom(currentRoom, inventory, moves);
			}
			// Been to room but haven't gotten Dragoncoin yet
			else
			{
				std::cout << "\n\nWelcome back to the Twins, house of Lord Frey\n"
			 		  << "Are you ready to pay the toll yet?\n"
					  << "1. Pay Toll\n2. Refuse\n";
				userChoice = intValidationRange(1,2);

				// Choose to pay toll
				if(userChoice == 1)
				{
					if(hasDragongold)
					{
						// To ensure user only has to pay toll one time
						setTollPaid(true);
						std::cout << "\n*You have paid toll and spent 1 Dragoncoin*\n*Dragoncoin removed from inventory*\n"
							  << "You are free to travel north to Winterfell now\n";
					
						std::vector<std::string>::iterator position = std::find(inventory->begin(), inventory->end(), "Dragoncoin");
						if (position != inventory->end()) // == myVector.end() means the element was not found
						{
							inventory->erase(position);
						}
	
						std::cout << "\n\nWould you like to travel to Winterfell now?\n1. Go to Winterfell\n2. Exit\n";
						userChoice = intValidationRange(1,2);

						if(userChoice == 1)
						{
							// Move user north
							currentRoom = currentRoom->getTop();
							currentRoom->enterRoom(currentRoom, inventory, moves);
						}
						else
						{
						}
					}
					else
					{
						std::cout << "\nNo money!?  Go back to Kings landing where you're from and come back with a Dragoncoin\n\n";
						std::cout << "\nWould you like to travel back south to Dragonstone now?\n1. Go to Dragonstone\n2. Exit\n";
						userChoice = intValidationRange(1,2);
	
						if(userChoice == 1)
						{
							// Move user south
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
					std::cout << "\n\nGood luck trying to find another way up north peasant\n\n";
				}
			}
		}
	}
	else
	{
		std::cout << "\n\n\nYou have used all your moves without defeating the Great Other!\n\nGOODBYE\n\n";
	}
}

void TheTwins::setTollPaid(bool boolIn)
{
	tollPaid = boolIn;
}

bool TheTwins::getTollPaid()
{
	return tollPaid;
}
