/**********************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Header file for NorthOfWall class
**********************************************************/

#ifndef NORTHOFWALL_HPP
#define NORTHOFWALL_HPP

#include <vector>
#include <string>

#include "Space.hpp"

class NorthOfWall : public Space
{
	public:
		NorthOfWall();
		~NorthOfWall();
		void enterRoom(Space*, std::vector<std::string>*, int&);
};

#endif
