/***********************************************************************
 * Module:  Box.h
 * Author:  Anton
 * Modified: Monday, January 16, 2017 4:29:43 AM
 * Purpose: Declaration of the class Box
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_1_Box_h)
#define __ObjectOrientedModel_1_Box_h

#include <vector>
#include <iostream>

class Cost;

class Box
{
public:
	//====constructors=====
	Box() :
	money(1),
	cost(1, new Cost)
	{
		std::cout << "Box created!!! (default)" << std::endl;
	}
   int checkInput(void);

  std::vector<Cost*> cost;

protected:
private:
   int money;
};

#endif