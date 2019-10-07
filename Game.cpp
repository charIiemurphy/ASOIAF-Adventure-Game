/***********************************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Defines member functions of Game class which drives the program
************************************************************************/

#include <iostream>

#include "Game.hpp"
#include "Space.hpp"
#include "KingsLanding.hpp"
#include "IsleOfFaces.hpp"
#include "Dragonstone.hpp"
#include "TheTwins.hpp"
#include "Winterfell.hpp"
#include "NorthOfWall.hpp"
#include "LandOfAlwaysWinter.hpp"


/************************************************************************
 * Description: Default constructor
************************************************************************/
Game::Game()
{

}

/***********************************************************************
 * Description: Destructor
***********************************************************************/
Game::~Game()
{
	for(int i = 0; i < 7; i++)
	{
		delete spaceArray[i];
	}
}

/***********************************************************************
 * Description: Will run most logic behind the game
***********************************************************************/
void Game::play()
{
	int moves = 12;
	spaceArray[0] = new KingsLanding;
	spaceArray[1] = new IsleOfFaces;
	spaceArray[2] = new Dragonstone;
	spaceArray[3] = new TheTwins;
	spaceArray[4] = new Winterfell;
	spaceArray[5] = new NorthOfWall;
	spaceArray[6] = new LandOfAlwaysWinter;
	Space* currentRoom     = nullptr;
	std::vector<std::string>* inventory = &inv;
	// Initialize pointer directions for map
	for(int i = 0; i < 6; i++)
	{
		spaceArray[i]->setTop(spaceArray[i+1]);
		spaceArray[i+1]->setBottom(spaceArray[i]);
	}
	spaceArray[0]->setBottom(nullptr);
	spaceArray[6]->setTop(nullptr);

	std::cout << "\n\nWelcome to my fantasy game based on George RR Martin's A Song of Ice and Fire"
		  << "\nYou are a lowly peasant from flea bottom.\n"
	          << "\nOne day you have a vision of some sort of black bird... with an extra eye even"
		  << "\nIt shows you a horrible force of undead marching south towards the wall"
	 	  << "\nYou know you must stop this so you begin traveling north to defeat this great threat"
		  << "\nYou will be able to move 10 steps only, choose wisely!"
		  << "\nYour journey begins in your home of Kings Landings, may the gods be with you!\n";
	
	currentRoom = spaceArray[0];	
	spaceArray[0]->enterRoom(currentRoom, inventory, moves);
	//currentRoom = nullptr;
	//inventory->clear();
	//inventory = nullptr;
}
























