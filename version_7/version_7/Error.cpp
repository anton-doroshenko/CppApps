#include "Error.h"

void Error::input(std::string *str)
{
	bool flag = false;

	while (true)
	{
		for (int i = 0; i < str->size(); i++)
		{
			//flag = ((*str)[i] < 48 || (*str)[i] > 57) ? true : false;
			if ((*str)[i] < 48 || (*str)[i] > 57)
			{
				flag = true;
				break;
			}
			else
			{
				flag = false;
			}
		}
		if (flag)
		{
			std::cout << "Incorrect input, please try again\n" << std::endl;
			std::cin >> *str;
		}
		else
		{
			break;
		}
	}
}

void Error::valOfCandidates()
{
	std::cout << "HR - manager can`t comunicate with more than 5 Candidates..." << std::endl;
}

void Error::valOfWorkers()
{
	std::cout << "Curent value of workers can`t be bigger than max value of workers" << std::endl;
}

void Error::err(std::string *str)
{
	switch (type)
	{
	case 1: input(str); break;
	case 2:  valOfCandidates(); break;
	case 3:  valOfWorkers();  break;
	}
}
