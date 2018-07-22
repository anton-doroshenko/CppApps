#include <iostream>

using namespace std;

#include <string>
#include "Cost.h"
#include "Card.h"
#include "Box.h"
#include "User.h"

int main()
{
	cout << "Start modeling..." << endl;
	User user;
	Box box;
	cout << box.cost[0]->getMoney() << endl;
	(*box.cost[0]) += 1000;
	++(*box.cost[0]);
	cout << box.cost[0]->getMoney() << endl;
	cout << "End modeling" << endl;
	system("pause");
}