/**********************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Header function for KingsLanding class
**********************************************************/

#ifndef KINGSLANDING_HPP
#define KINGSLANDING_HPP

#include <string>
#include <vector>

#include "Space.hpp"

class KingsLanding : public Space
{
	public:
		KingsLanding();
		~KingsLanding();
		void enterRoom(Space*, std::vector<std::string>*, int&);
};

#endif
