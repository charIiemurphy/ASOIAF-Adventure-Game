/*****************************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Header file for Space class
*****************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <vector>
#include <string>

class Space
{
	protected:
		Space *top;
		Space *right;
		Space *bottom;
		Space *left;
		bool roomVisited;
	public:
		Space();
		~Space();
		virtual void enterRoom(Space*, std::vector<std::string>*, int&);
		virtual void setRoomVisited(bool);
		virtual bool getRoomVisited();
		virtual void setTop(Space*);
		virtual Space* getTop();
		virtual void setBottom(Space*);
		virtual Space* getBottom();
};

#endif
