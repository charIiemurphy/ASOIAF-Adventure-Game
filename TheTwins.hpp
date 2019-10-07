/**********************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Header file for TheTwins class
**********************************************************/

#ifndef TheTwins_HPP
#define TheTwins_HPP

#include <vector>
#include <string>

#include "Space.hpp"

class TheTwins : public Space
{
	private: 
		bool tollPaid;
	public:
		TheTwins();
		~TheTwins();
		void enterRoom(Space*, std::vector<std::string>*, int&);
		void setTollPaid(bool);
		bool getTollPaid();
};

#endif
