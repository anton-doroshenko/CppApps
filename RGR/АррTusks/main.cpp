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
bool flagb = true;
int g;//найбільший спільний дільник

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
		flag = false;
	}
	else
	{
		div = gcd(a, b, x, y);
		if (c % div != 0)
		{
			flag = false;
		}
		else
		{
			x *= c / div;
			y *= c / div;
		}
	}
	g = div;
}
//====Функція виведення коренів діафантового рівняння на заданому відрізку======
void  printRoots(int left, int right, int step, int a, int b, int c, char k)
{
	int index = 1;
	if (k == '1')
	{
		cout << "Amount of sharing options is " << (right - left) / step + 1 << endl;
		for (int i = left; i <= right; i += step)
		{
			cout << index << ". " << "amount bancknots of " << a << ": " << i << "  amount bancknots of "<< b <<": "<< (c - (a * i)) / b << endl;
			index++;
		}
	}
	else if (k == '2')
	{
		if (flagb)
		{
			cout << "Yes, we can" << endl;
		}
		else
		{
			cout << "No, we can`t" << endl;
		}
	}
	else if (k == '3')
	{
		if (flagb)
		{
			cout << "amount segments of " << a << ": " << left << "  amount segments of " << b << ": " << (c - (a * left)) / b << endl;
		}
		else
		{
			cout << "There is no solution" << endl;
		}
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
			flagb = false;
			printRoots(leftx, rightx, stepx, a * g, b * g, c, key);
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
				y -= stepy;
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
			flagb = false;
			printRoots(leftx, rightx, stepx, a * g, b * g, c, key);
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
			flagb = false;
		}
		printRoots(leftx, rightx, stepx, a * g, b * g, c, key);
	}
	else
	{
		flagb = false;
		printRoots(1, 0, 1, a * g, b * g, c, key);
	}
	return 0;
}

void firstTask()
{
	cout << "Tusk" << endl;
	cout << "We want to exchange cash a check for a certain number banknotes of n and m. How many sharing options?" << endl;
	cout << "Enter value of cash check to exchange (for example 100):" << endl;
	cin >> c;
	cout << "Enter value of banknotes (for example 5 20):" << endl;
	cin >> a >> b;
	searchAllSolutionsOnLength(a, b, c, 0, 0, c, c);
}

void secondTask()
{
	cout << "Tusk" << endl;
	cout << "Can we weigh 'c' grams of certain substances on the scales\nif we have only 'x' weights of 'a' grams and 'y' weights of 'b' grams?" << endl;
	cout << "Enter a, b, c:" << endl;
	cin >> a >> b >> c;
	searchAllSolutionsOnLength(a, b, c, 0, 0, c, c);

}

void thirdTask()
{
	cout << "How much segments of length 'a' cm long and how many segments of 'b' cm we must take to constitute one segment length of c cm?" << endl;
	cout << "Enter a, b, c:" << endl;
	cin >> a >> b >> c;
	searchAllSolutionsOnLength(a, b, c, 0, 0, c, c);
}

int main()
{ 
	system("color F0");
	while (true)
	{
		flagb = true;
		system("cls");
		cout << "Menu" << endl;
		cout << "1.First task" << endl;
		cout << "2.Second task" << endl;
		cout << "3.Third task" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter your choose: ";
		cin >> key;
		switch (key)
		{
		case '1':
		{
					firstTask();
					system("pause");
		};
			break;
		case '2':
		{
					secondTask();
					system("pause");
		};
			break;
		case '3':
		{
					thirdTask();
					system("pause");
		};
			break;
		case '4': exit(0);
			break;
		default: cout << "Please, try again..." << endl;
			system("pause");
			break;
		}
	}
}