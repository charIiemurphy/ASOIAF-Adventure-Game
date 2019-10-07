/**********************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Member functions of LandOfAlwaysWinter class
**********************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "Space.hpp"
#include "LandOfAlwaysWinter.hpp"
#include "intValidationRange.hpp"

/*********************************************************
 * Description: Constructor for LandOfAlwaysWinter
*********************************************************/
LandOfAlwaysWinter::LandOfAlwaysWinter()
{
	roomVisited = false;	 
}

/*********************************************************
 * Description: Destructor
*********************************************************/
LandOfAlwaysWinter::~LandOfAlwaysWinter()
{

}

/********************************************************
 * Description: Events that occur once player enters
********************************************************/
void LandOfAlwaysWinter::enterRoom(Space* currentRoom, std::vector<std::string>* inventory, int& moves)
{
	std::cout << "\n\nWelcome to the land of always winter!\nIts too cold here and you froze to death.\n"
		  << "Could have really used a hot pie right now\nTHE END!!!\n\n";
}
