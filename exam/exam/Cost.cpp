/***********************************************************************
 * Module:  Cost.cpp
 * Author:  Anton
 * Modified: Monday, January 16, 2017 4:34:52 AM
 * Purpose: Implementation of the class Cost
 ***********************************************************************/

#include "Cost.h"

////////////////////////////////////////////////////////////////////////
// Name:       Cost::getMoney()
// Purpose:    Implementation of Cost::getMoney()
// Return:     int
////////////////////////////////////////////////////////////////////////

//int Cost::getMoney(void)
//{
//   // TODO : implement
//	return 0;
//}
Cost Cost::operator +=(int a)
{
	   this->money = this->money + a;
	   std::cout << "Cwwwwwwwwwwwwwwwwwwwwwwwww" << std::endl;
	   return *this;
}
Cost& Cost::operator ++()
{
	this->money++;
	std::cout << "Cwwwwwwwwwwwwwwwwwwwwwwwww" << std::endl;
	return *this;
}
////////////////////////////////////////////////////////////////////////
// Name:       Cost::setMoney()
// Purpose:    Implementation of Cost::setMoney()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Cost::setMoney(void)
{
   // TODO : implement
}