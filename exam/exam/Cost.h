/***********************************************************************
 * Module:  Cost.h
 * Author:  Anton
 * Modified: Monday, January 16, 2017 4:34:52 AM
 * Purpose: Declaration of the class Cost
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_1_Cost_h)
#define __ObjectOrientedModel_1_Cost_h
#include <iostream>
class Cost
{
public:
	//====constructors=====
	Cost() :
		money(1)
	{
		std::cout << "Cost created!!! (default)" << std::endl;
	}
	int getMoney(void)
	{
		return money;
	}
   void setMoney(void);

   Cost operator += (int);
   Cost& operator++ ();
protected:
private:
   int money;
};

#endif