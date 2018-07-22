//Laboratory work
//written by student of the first curse
//of the group IC-52
//Anton Doroshenko
//2016.03.26
//==========================================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define N 2
#define MAX(a, b) ((a) > (b)) ? (a) : (b)
#define MIN(c, d) ((c) < (d)) ? (c) : (d)
#define CUBE(e) (e) * (e) * (e)
#define SQR(f) (f) * (f)

double x, y, z;
double f;               //значення функції
int ans = 0;            //ознака завершення введення даних
double mx, mn;          //змінні для проміжних результатів

int main()
{
	cout << "laboratory work number 3 made by Anton Doroshenko, IS-52" << endl;
	do
	{
		#if N == 1
		cout << "Const = " << N << endl;
		cout << "Input three numbers" << endl;
		cin >> x >> y >> z;
		f = max((x * x * x), (x + y) * (x + y)) * min((x - y), (y - z));
		cout << f << endl;
		mx = MAX(CUBE(x), SQR(x + y));
		mn = MIN((x - y), (y - z));
		f = mx * mn;
		cout << "Result: " << f << endl;
		#else
		cout << "Const = " << N << endl;
		cout << "Input two numbers" << endl;
		cin >> x >> z;
		f = MIN(fabs(x - z), fabs(x + z));
		cout << "Result: " << f << endl;
		#endif
		cout << "Do you want to start again? ('yes' - 1)" << endl;
		cin >> ans;
	} while (ans == 1);
}