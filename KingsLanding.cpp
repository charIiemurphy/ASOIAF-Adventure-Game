/**********************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Member functions of KingsLanding class
**********************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "intValidationRange.hpp"
#include "Space.hpp"
#include "KingsLanding.hpp"
#include "IsleOfFaces.hpp"

/*********************************************************
 * Description: Constructor for KingsLanding
*********************************************************/
KingsLanding::KingsLanding()
{
	roomVisited = false;	 
}

/*********************************************************
 * Description: Destructor
*********************************************************/
KingsLanding::~KingsLanding()
{

}

/********************************************************
 * Description: Events that occur once player enters
********************************************************/
void KingsLanding::enterRoom(Space* currentRoom, std::vector<std::string>* inventory, int& moves)
{
	// Decrements moves counter
	moves--;

	// If user hasn't used all 10 moves
	if(moves > 0)
	{
		// Sets boolean on if user has Dragongold	
		bool hasCoin;
		int userChoice;
		for(int i = 0; i < inventory->size(); i++)
		{
			if(inventory->at(i) == "Dragongold")
			{
				hasCoin = true;
			}
			else
			{
				hasCoin = false;
			}
		}


		// If first time visiting room
		if(!roomVisited)
		{
			// Set roomVisited to true once user enters room first time
			setRoomVisited(true);
			
			std::cout << "\n\nYour journey begins in Kings Landing, your home.\nYou must figure out a way north!\n"
				  << "You must save your family and the realm.\nIn your vision the three eyed ... raven was it?"
				  << " Showed you a view of Isle of Faces\nThere must be something important there...\n"
				  << "But first you must gather some money for the long road ahead\n\n\n"
				  << "You find a merchant who offers you 1 dragongold if you can answer a trivia question correctly!\n\n"
				  << "Hello little peasant! What was the name of the Targaryan king who first conquered westeros?\n"
				  << "1. Baelor\n2. Visery\n3. Aegon\n4. Aerys\n";
			userChoice = intValidationRange(1,4);

			// 3 is correct answer
			if(userChoice == 3)
			{
				std::cout << "\nCorrect!\nYou're smart for some flea bottom scum.  Heres the dragongold I promised\n"
					  << "*Dragongold added to inventory*\n";
				inventory->push_back("Dragongold");
			}
			else
			{
				std::cout << "\nHA HA HA, you really are from flea bottom!\nCome back another day and try again\n";
			}
		
			std::cout << "The only direction you can travel is north.  Would you like to\n"
				  << "1. Travel to Isle of Faces\n2. Exit\n";
			userChoice = intValidationRange(1,2);
		
			// User chooses to go to Isle of Faces
			if(userChoice == 1)
			{
				int takepie;
				std::cout << "\nOn your way out of King's landing your friend Hot Pie sees you leaving\n"
					  << "He stops you and offers a hotpie as a parting gift\n"
					  << "You only can carry 3 items and still need a jacket and dragonglass for north of the wall...\n"
					  << "1. Refuse\n"
					  << "2. Take hotpie\n";
				takepie = intValidationRange(1,2);

				if(takepie == 1)
				{
					std::cout << "\nHot Pie runs away crying :( \n\n";
				}
				else
				{	
					std::cout << "\n*hotpie added to inventory*\n\n";
					inventory->push_back("hotpie");
				}
				// Enter next room
				currentRoom = currentRoom->getTop();
				currentRoom->enterRoom(currentRoom, inventory, moves);
			}
			else
			{
			}
		}
		// Been to room and already got Dragoncoin
		else 
		{	
			if (roomVisited && hasCoin)
			{
				std::cout << "\n\nWelcome back to King's Landing!\n\n";
		
				std::cout << "The only direction you can travel is north.  Would you like to\n"
					  << "1. Travel to Isle of Faces\n2. Exit\n";
				userChoice = intValidationRange(1,2);
				
				if(userChoice == 1)
				{
					currentRoom = currentRoom->getTop();
					currentRoom->enterRoom(currentRoom, inventory, moves);
				}
				else
				{
				}
			}
			// Been to room but haven't gotten Dragoncoin yet
			else
			{				
				std::cout << "\n\nWelcome back to Kings Landing!\nYou have arrived back to the merchant\n"
					  << "HAR! Ready to try again?\nWhat was the name of the Targaryan king who first conquered westeros?\n"
					  << "1. Baelor\n2. Visery\n3. Aegon\n4. Aerys\n";
				userChoice = intValidationRange(1,4);
		
				// 3 Is correct answer
				if(userChoice == 3)
				{
					std::cout << "\nCorrect!\nYou're smart for some flea bottom scum.  Here is the dragongold I promised\n"
						  << "*Dragongold added to inventory*\n";
					inventory->push_back("Dragongold");
				}
				else
				{
					std::cout << "\nHA HA HA, you really are from flea bottom!\nCome back another day and try again\n";
				}
			
				std::cout << "The only direction you can travel is north.  Would you like to\n"
					  << "1. Travel to Isle of Faces\n2. Exit\n";
				userChoice = intValidationRange(1,2);
			
				// User chooses to travel up
				if(userChoice == 1)
				{
					currentRoom = currentRoom->getTop();
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
