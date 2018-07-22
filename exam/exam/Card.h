/***********************************************************************
 * Module:  Card.h
 * Author:  Anton
 * Modified: Monday, January 16, 2017 4:33:25 AM
 * Purpose: Declaration of the class Card
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_1_Card_h)
#define __ObjectOrientedModel_1_Card_h

#include <iostream>

class Card
{
public:
	//====constructors=====
	Card():
		pin(1),
		number(2)
	{
		std::cout << "Card created!!! (default)" << std::endl;
	}
   void addMoney(void);

protected:
private:
   int pin;
   int number;


};

#endif