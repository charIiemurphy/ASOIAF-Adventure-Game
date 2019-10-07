/**********************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Header file for LandOfAlwaysWinter class
**********************************************************/

#ifndef LANDOFALWAYSWINTER_HPP
#define LANDOFALWAYSWINTER_HPP

#include <vector>
#include <string>

#include "Space.hpp"

class LandOfAlwaysWinter : public Space
{
	public:
		LandOfAlwaysWinter();
		~LandOfAlwaysWinter();
		void enterRoom(Space*, std::vector<std::string>*, int&);
};

#endif
