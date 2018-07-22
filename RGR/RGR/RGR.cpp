#include <iostream>
#include <algorithm>

using namespace std;

char key;            //номер пункту меню
int x, y;//невідомі змінні
int a, b, c;//відомі коефіцієнти
int minx, miny, maxx, maxy;//границі значення яких вводить користувач
int rightx;//реальна границя для х
int leftx;//реальна границя для у
bool flag = true;//булева змінна, що показує чи є розв'язки чи ні
int g;//найбільший спільний дільник
int n; //задане число для модульного лінійного рівняння

//====Розширений алгоритм Евкліда для пошуку НСД======
int gcd(int a, int b, int & x, int & y)
{
	if (a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
//====Функція пошуку одного з рішень діафантового рівняння======
void searchOneSolve(int a, int b, int c, int & x, int & y)
{
	int div = 0;
	if (a == 0 && b == 0)
	{
		if (c == 0)
		{
			cout << "The amount of roots is infinity" << endl;
		}
		else
		{
			cout << "There are not roots" << endl;
		}
		flag = false;
	}
	else
	{
		div = gcd(a, b, x, y);
		if (c % div != 0)
		{
			cout << "There are not roots" << endl;
			flag = false;
		}
		else
		{
			x *= c / div;
			y *= c / div;
			cout << "One solution is:\nx = " << x << "\ny = " << y << endl;
		}
	}
	g = div;
}
//====Функція виведення коренів діафантового рівняння на заданому відрізку======
void  printRoots(int left, int right, int step, int a, int b, int c, char k)
{
	int index = 1;
	cout << "Amount of roots is " << (right - left) / step + 1 << endl;
	for (int i = left; i <= right; i += step)
	{
		if (k == '2' || k == '3')
		{
			cout << index << ". " << "x = " << i << " y = " << (c - (a * i)) / b << endl;
		}
		if (k == '4')
		{
			cout << index << ". " << "x = " << i << endl;
		}
		index++;
	}
}
//====Функція виведення кореня найменшої суми х + у=====
void printRootWithMinSum(int left, int right, int a, int b, int c)
{
	if (a == b)
	{
		cout << "All roots have similar sum (x + y = const)" << endl;
	}
	else if (a < 0 && b > 0 || a > 0 && b < 0)
	{
		cout << "Answer is:" << endl;
		cout << "x = " << left << " y = " << (c - (a * left)) / b << endl;
	}
	else if (a < b)
	{
		cout << "Answer is:" << endl;
		cout << "x = " << left << " y = " << (c - (a * left)) / b << endl;
	}
	else
	{
		cout << "Answer is:" << endl;
		cout << "x = " << right << " y = " << (c - (a * right)) / b << endl;
	}
}
//====Фунуція пошуку усіх коренів діафантового рівняння на заданому відрізку====
int searchAllSolutionsOnLength(int a, int b, int c, int minx, int miny, int maxx, int maxy)
{
	searchOneSolve(a, b, c, x, y);
	if (flag)
	{
		bool flag2 = true;
		if ((a < 0 && b > 0) || (a > 0 && b < 0))
		{
			flag2 = false;
		}
		a /= g;
		b /= g;
		int stepx = b;//крок зміни х
		int stepy = a;//крок зміни н
		if (a < 0)
		{
			stepy *= -1;
		}
		if (b < 0)
		{
			stepx *= -1;
		}
		y -= ((minx - x) / b) * a;
		x += ((minx - x) / b) * b;
		if (x < minx)
		{
			x += stepx;
			if (flag2)
			{
				y -= stepy;
			}
			else
			{
				y += stepy;
			}
		}
		if (x > maxx)
		{
			cout << "There are not roots on this line segment" << endl;
			return 0;
		}
		int leftx1 = x;

		y -= ((maxx - x) / b) * a;
		x += ((maxx - x) / b) * b;
		if (x > maxx)
		{
			x -= stepx;
			if (flag2)
			{
				y += stepy;
			}
			else
			{
				y-= stepy;
			}
		}
		int rightx1 = x;

		x -= ((miny - y) / a) * b;
		y += ((miny - y) / a) * a;
		if (y < miny)
		{
			y += stepy;
			if (flag2)
			{
				x -= stepx;
			}
			else
			{
				x += stepx;
			}
		}
		if (y > maxy)
		{
			cout << "There are not roots on this line segment" << endl;
			return 0;
		}
		int leftx2 = x;

		x -= ((maxy - y) / a) * b;
		y += ((maxy - y) / a) * a;
		if (x > maxy)
		{
			y -= stepy;
			if (flag2)
			{
				x += stepx;
			}
			else
			{
				y -= stepx;
			}
		}
		int rightx2 = x;
		if (leftx2 > rightx2)
		{
			swap(leftx2, rightx2);
		}
		rightx = min(rightx1, rightx2);
		leftx = max(leftx1, leftx2);
		if (leftx > rightx)
		{
			cout << "There are not roots on this line segment" << endl;
		}
		else
		{
			printRoots(leftx, rightx, stepx, a * g, b * g, c, key);
		}	
	}
	return 0;
}
//===Завдання===
void task()
{
	cout << "Grafic rated work made by student of first curse of grupe IS - 52\nAnton Doroshenko" << endl;
	cout << "========Topic==========" << endl;
	cout << "- Diophantine equation with two unknowns: AX + BY = C" << endl;
	cout << "- The modular linear first - order equation : AX = B" << endl;
	system("pause");
}
//====Меню програми====
void menu()
{
	while (true)
	{
		system("cls");
		cout << "Menu" << endl;
		cout << "1.Find any solution" << endl;
		cout << "2.Find the number of solutions and the solutions themselves in a certain segment" << endl;
		cout << "3.Find solution with minimal sum x + y" << endl;
		cout << "4.Modular linear first-order equation" << endl;
		cout << "5.Exit" << endl;
		cout << "Enter your choose: ";
		cin >> key;
		switch (key)
		{
		case '1':
		{
					cout << "Enter a, b, c:" << endl;
					cin >> a >> b >> c;
					searchOneSolve(a, b, c, x, y);
					system("pause");
		};
			break;
		case '2':
		{
					cout << "Enter a, b, c:" << endl;
					cin >> a >> b >> c;
					cout << "Enter borders for x and for y (first minx, maxx, then miny, maxy)" << endl;
					cin >> minx >> maxx >> miny >> maxy;
					searchAllSolutionsOnLength(a, b, c, minx, miny, maxx, maxy);
					system("pause");
		};
			break;
		case '3':
		{
					cout << "Enter a, b, c:" << endl;
					cin >> a >> b >> c;
					cout << "Enter borders for x and for y" << endl;
					cin >> minx >> maxx >> miny >> maxy;
					searchAllSolutionsOnLength(a, b, c, minx, miny, maxx, maxy);
					printRootWithMinSum(leftx, rightx, a, b, c);
					system("pause");
		};
			break;
		case '4':
		{
					cout << "Enter a, b, n:" << endl;
					cin >> a >> c >> n;
					cout << "Enter borders for x" << endl;
					cin >> minx >> maxx;
					if (n < 0 && c > 0 || n > 0 && c < 0)
					{
						miny = (c - (a * minx)) / n;
						maxy = (c - (a * maxx)) / n;
					}
					else
					{
						maxy = (c - (a * minx)) / n;
						miny = (c - (a * maxx)) / n;
					}
					searchAllSolutionsOnLength(a, n, c, minx, miny, maxx, maxy);
					system("pause");
		};
			break;
		case '5': exit(0);
			break;
		default: cout << "Please, try again..." << endl;
			system("pause");
			break;
		}
	}
}
//====Головна функція====
int main()
{
	system("color F0");
	task();
	menu();
}