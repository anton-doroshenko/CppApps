/***********************************************************************
 * Module:  User.h
 * Author:  Anton
 * Modified: Monday, January 16, 2017 4:32:45 AM
 * Purpose: Declaration of the class User
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_1_User_h)
#define __ObjectOrientedModel_1_User_h

#include <iostream>
#include <string>
#include <vector>

class Card;
class Box;

class User
{
public:
	//====constructors=====
	User():
		name("tttt"),
		card(1)
	{
		std::cout << "User created!!! (default)" << std::endl;
	}
	User(std::string nam) :
		name(nam),
		card(1)
	{
		std::cout << "User created!!! (innicialisation)" << std::endl;
	}
	User(User &user) :
		name(user.name),
		card(1)
	{
		std::cout << "User created!!! (copy)" << std::endl;
	}
	//===destructor===
	~User(){}

   void inputPin(void);
   void watchBalance(void);
   void getMoney(void);
   void changePin(void);
   void blockCard(void);

   std::vector<Card> card;
   std::vector<Box*> box;

protected:
private:
   std::string name;


};

#endif