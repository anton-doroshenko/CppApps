//Laboratory work
//written by student of the first curse
//of the group IC-52
//Anton Doroshenko
//2015.10.25
//==========================================================================

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double calculating(double error);
const double minerror = 0.00015; // мінімальна точність обчисленнь

int main()

{
	cout << "Lab_3, IS-52, variant 9, made by Anton Doroshenko " << endl;
	cout << "calculate the sum of row" << endl;
	double error;                                // похибка
	int cont;                                    // параметр умови продовження обчисленнь
	do
	{
		cout << "Please enter 'error' " << endl;		
		cin >> error;
		if (error >= minerror)                   // умова запобігання переповнення комірки пам'яті
		{
			double result = calculating(error);  // результат обчисленнь
			cout << "result = " << result << endl;
		}
		else
			cout << "overflow because error is very small\nResult is not correct\nPlease try again" << endl;
		cout << "If you want to start again enter 1" << endl;
		cin >> cont;
	} while (cont == 1);                         // умова продовження обчисленнь
}

double calculating(double error)            // функція для обчисленнь 
{
	double result = 0;
	cout << "x" << setw(10) << "k" << setw(20) << "sum" << setw(20) << "result" << endl;
	cout << "___________________________________________________" << endl;
	for (int x = 1; x <= 5; x++)
	{  // х - параметр зовнішньої функції
		double sum = 0;                     // внутрішня сума
		double divsn;                       // елемент ряду (дріб)
		int k = 1;                          //параметр внутрішньої суми
		int denum = 0;                      //знаменник дробу

		do
		{
			//-----обчислення чисельника дробу-----
			double numenator = pow(-1, k) * pow(x, (k - 1));
			//-----обчислення знаменника дробу-----
			int i = 2*k;                    // лічильник 
			int mul = 1;                    // доданок знаменника
			while (k <= i)
				mul *= i--;
			denum += mul;
			//-----обчислення дробу і внутрішньої суми-----
			divsn = ((double) numenator) / ((double) denum);
			sum += divsn;
			//-----виведення поточних розрахунків-----
			cout << x << setw(10) << k << setw(20) << sum << setw(20) << (result+sum) << endl;
			k++;
		} while (fabs(divsn) > error);      //поки не досягнуто заданої точності
		result += sum;                      //остаточний результат
	}
	return result;
}

