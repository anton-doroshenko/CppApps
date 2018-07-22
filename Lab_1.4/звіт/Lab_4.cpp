//Laboratory work
//written by student of the first curse
//of the group IC-52
//Anton Doroshenko
//2015.11.01
//==========================================================================

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double t = 0;                           //точність розрахунків

double ln(double a)
{
	int i = 2;                         //лічильник членів ряду
	double member = a - 1;              //перший член ряду
	double sum = member;                 //сума ряду
	while (fabs(member) > t)           //доки поточний член не задовольняє точності
	{
		member *= -(a - 1);      //обчислювати поточний член 
		//member = member / i;
		sum += member / i;                 //і суму ряду
		i++;
		if (i == 1000)
			break;
	}
	return sum;                        //повернення значення натурального логарифму
}

int main()
{
	cout << "laboratory work number 4 made by Anton Doroshenko, IS-52" << endl;
	bool flag = true;
	double x, teylorsum, standart;      //аргумент, вираз за формулою Тейлора, значення стандартної функції log()
	double xstart, step, xend;          //початкове значення аргументу, крок зміни, кінцеве значення аргументу
	double error;                       //похибка
	int cont;
	do
	{
		cout << "Enter xstart, xend and step (-2 2 0.5)" << endl;
		cin >> xstart >> xend >> step;
		cout << "Input t" << endl;
		cin >> t;
		cout << setw(5) << "x" << setw(20) << "teylorsum" << setw(25) << "standart" << setw(20) << "error" << endl;
		cout << "========================================================================" << endl;
		for (x = xstart; x <= xend; x += step)        //цикл перебору значень аргументів функції
		{
			if (x > 0 && x <= 1)
			{
				teylorsum = ln(x / 2) - 1;            //визначення функції за формулою Тейлора
				standart = log(x / 2) - 1;            //визначення функції за стандартною формулою
				error = fabs(standart - teylorsum);   //розбіжності між точним і наближеним значенням функції
				flag = true;                          //функція визначена
			}
			else 
				flag = false;                         //функція не визначена
			if (flag == true)
			{
				cout << setw(5) << x << setw(20) << teylorsum << setw(25) << standart << setw(20) << error << endl;
				cout << " " << endl;
			}
			else
			{
				cout << setw(5) << x << setw(35) << "not defined" << endl;
				cout << " " << endl;
			}
		}
		cout << "Enter 1 if you want to start again" << endl;
		cin >> cont;
	} while (cont == 1);
}
