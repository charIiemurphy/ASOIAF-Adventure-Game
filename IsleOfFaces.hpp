/**********************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Header function for IsleOfFaces class
**********************************************************/

#ifndef ISLEOFFACES_HPP
#define ISLEOFFACES_HPP

#include <string>
#include <vector>

#include "Space.hpp"

class IsleOfFaces : public Space
{
	public:
		IsleOfFaces();
		~IsleOfFaces();
		void enterRoom(Space*, std::vector<std::string>*, int&);
};

#endif
