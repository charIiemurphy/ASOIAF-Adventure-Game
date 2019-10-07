/**********************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Header file for Winterfell class
**********************************************************/

#ifndef WINTERFELL_HPP
#define WINTERFELL_HPP

#include <vector>
#include <string>

#include "Space.hpp"

class Winterfell : public Space
{
	public:
		Winterfell();
		~Winterfell();
		void enterRoom(Space*, std::vector<std::string>*, int&);
};

#endif
