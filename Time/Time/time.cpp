//пример использования функции ctime
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

int main()
{ 
	long i = 0;
	time_t rawtime;
	while (true)
	{
		i++;
		time(&rawtime); // текущая дата в секундах
		if (i == 10000000)
		{
			system("cls");
			std::cout << "Текущее локальное время и дата: "
				<< ctime(&rawtime);// текущая дата в понятной для человека форме
			i = 0;
		} 
	}
	return 0;
}