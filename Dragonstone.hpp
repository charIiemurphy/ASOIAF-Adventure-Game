/**********************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Header file for Dragonstone class
**********************************************************/

#ifndef DRAGONSTONE_HPP
#define DRAGONSTONE_HPP

#include <vector>
#include <string>

#include "Space.hpp"

class Dragonstone : public Space
{
	public:
		Dragonstone();
		~Dragonstone();
		void enterRoom(Space*, std::vector<std::string>*, int&);
};

#endif
