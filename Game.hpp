/*********************************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Header file for Game class
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>

#include "Space.hpp"

class Game
{
	private:
		Space *spaceArray[7];
		std::vector<std::string> inv;

	public:
		Game();
		~Game();
		void play();
};

#endif
