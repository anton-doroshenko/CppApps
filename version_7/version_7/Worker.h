#if !defined(Worker_h)
#define Worker_h

#include <iostream>
#include<string>
#include "Hr_manager.h"

//class Hr_manager;

class Worker
{
public:

	Worker() : name("TEMP") {}
	Worker(std::string n) : name(n) {}

	~Worker() {}

	virtual void showPosition()
	{
		std::cout << "worker" << std::endl;
	}

	std::string getName(void)
	{
		return name;
	}
protected:
	const std::string name;
private:
};

#endif