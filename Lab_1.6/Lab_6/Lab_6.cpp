//Laboratory work
//written by student of the first curse
//of the group IC-52
//Anton Doroshenko
//2015.11.16
//==========================================================================

#include <iostream>
#include <math.h>

using namespace std;

double step = 0.0001;        //крок зміни для методу перебору
double sx1 = 0,              //перший корінь знайдений методом перебору
       sx2 = 0;              //другий корінь знайдений методом перебору
double chx1 = 0,             //перший корінь знайдений методом хорд
       chx2 = 0;             //другий корінь знайдений методом хорд
double a = 0;                //нижня границя проміжка
double b = 0;                //верхня границя проміка
double error = 0.0001;       //точність для методу хорд
//--------обчислення значення функції-----------
double func(double *par)
{
	return (*par) * (*par) - exp(-(*par) * (*par));
}
//-----знаходження кореня методом перебору-----
double search(double *a, double *step, double *x)
{
	*x = *a + *step;
	while (func(a) * func(x) > 0)
	{
		*x += *step;
	}
	return *x;
}
//------знаходження кореня методом хорд------
double chord(double *a, double *b, double *x)
{
	while (fabs(func(x)) >= error)
	{
		*x = *a + fabs(func(a) / (func(a) - func(b)))*(*b - *a);
		if (func(a) < 0)
			a = x;
		else
			b = x;
	}
	return *x;
}

int main()
{
	int cont = 0;
	cout << "laboratory work number 6 made by Anton Doroshenko, IS-52" << endl;
	do
	{
		cout << "Please, enter lower and upper bound" << endl;
		cin >> a >> b;
		double* point_sx1 = &sx1;   //покажчик на перший корінь знайдений методом перебору
		double* point_sx2 = &sx2;   //покажчик на другий корінь знайдений методом перебору
		double* point_chx1 = &chx1; //покажчик на перший корінь знайдений методом хорд
		double* point_chx2 = &chx2; //покажчик на другий корінь знайдений методом хорд
		double* point_step = &step; //покажчик на крок зміни для методу перебору
		double* point_a = &a;       //покажчик на нижню границю проміжка
		double* point_b = &b;       //покажчик на верхню границю проміжка

		if (func(point_a) * func(point_b) < 0)//умова коли рівняння на проміжку має один корінь
		{
			cout << "one root" << endl;
			sx1 = search(point_a, point_step, point_sx1);
			cout << "root search = " << sx1 << endl;
			chx1 = chord(point_a, point_b, point_chx1);
			cout << "chord root = " << chx1 << endl;

		}
		else if (func(point_a) * func(point_b) >= 0)
		{
			if (func(point_a) >= 0 && a < 0)//два корені
			{
				//-----відокремлення коренів-----
				cout << "2 roots" << endl;
				double asec,                //нижня границя проміжка де знаходиться 2 корінь
					   bsec;                //верхня границя проміжка де знаходиться 2 корінь
				double* point_asec = &asec; //покажчик на нижню границю
				double* point_bsec = &bsec; //покажчик на верхню границю
				*point_asec = 0;
				*point_bsec = *point_b;
				*point_b = 0;
				//-----уточнення коренів-----
				cout << "first root" << endl;
				sx1 = search(point_a, point_step, point_sx1);
				cout << "search root  = " << sx1 << endl;
				chx1 = chord(point_a, point_b, point_chx1);
				cout << "chord root = " << chx1 << endl;
				cout << "second root" << endl;
				sx2 = search(point_asec, point_step, point_sx2);
				cout << "search root  = " << sx2 << endl;
				chx2 = chord(point_asec, point_bsec, point_chx2);
				cout << "chord root = " << chx2 << endl;
			}
			else//інакше коренів немає
				cout << "There are not roots" << endl;
		}
		cout << "If you want start again enter 1" << endl;
		cin >> cont;
	} while (cont == 1);
}