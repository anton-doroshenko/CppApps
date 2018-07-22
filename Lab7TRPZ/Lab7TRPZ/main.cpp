#include <iostream>
#include "Solver.h"
#include <math.h>
#include <regex>
#include <stdlib.h>

using namespace std;

double inputNumber()
{
	string str;
	double number;

	cin >> str;
	try{
		number = stod(str);
	}
	catch(exception e){
		cout << "Try again: ";
		number = inputNumber();
	}
	return number;
}

int main()
{
	double pi = 3.141592653589793;
	char ch = 'Y';
	while (true){
		double x = -30370005000.0;
		double error = 0.0001;
		do{
			cout << "Input x in range (0, 5]: " << endl;
			x = inputNumber();
		} while (x <= 0 || x > 5);
		//cout.precision(15);
		//cout << fixed << x << endl;
		do{
			cout << "Input error in range (0, 1): " << endl;
			error = inputNumber();
		} while (error >= 1.0 || error <= 0);
		//cout << error << endl;
		try{
			Solver solver(x, error);
			cout << "Standart result: " << (x + 3) / sin(x) << endl;
			cout <<"Teylor result: "<< solver.Solve() << endl;
		}
		catch (const std::overflow_error& e)
		{
			cout << "Error: " << e.what() << endl;
		}
		cout << "Do you want to continiue? (Y/n)" << endl;
		cin >> ch;
		cin.clear();
		if (ch == 'Y' || ch == 'y')
			continue;
		else
			break;
	}
	
	system("pause");
	return 0;
}