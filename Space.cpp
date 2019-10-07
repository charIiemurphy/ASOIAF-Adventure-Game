/******************************************************************
 * Name: Charles Kusk
 * Date: June 10, 2019
 * Description: Defines member functions of Space class
******************************************************************/

#include "Space.hpp"

Space::Space()
{
	right = nullptr;
	left = nullptr;
}

Space::~Space()
{

}

/*****************************************************************
 * Description: Where main actions of room will occur
*****************************************************************/
void Space::enterRoom(Space*, std::vector<std::string>*, int&)
{

}

void Space::setRoomVisited(bool roomVisitedIn)
{
	roomVisited = roomVisitedIn;
}

bool Space::getRoomVisited()
{
	return roomVisited;
}

void Space::setTop(Space* topIn)
{
	top = topIn;
}

Space* Space::getTop()
{
	return top;
}

void Space::setBottom(Space* bottomIn)
{
	bottom = bottomIn;
}

Space* Space::getBottom()
{
	return bottom;
}

