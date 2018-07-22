//Laboratory work
//written by student of the first curse
//of the group IC-52
//Anton Doroshenko
//2015.11.29
//==========================================================================
#include <iostream>
#include <time.h>

using namespace std;

int m = 0;//кількість стовчиків
int n = 0;//кількість рядків
int array[10][10];//матриця
int ArraySum[10];//масив сум елементів рядків
//====== Функція генерації матриці ======
void input()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = rand() % 50;
		}
	}
}
//====== Функція виведення матриці ======
void output()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}
//====== Функція знаходження сум елементів рядків ======
void SearchSum()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ArraySum[i] += array[i][j];
		}
	}
}
//====== Функція виведення масиву сум елементів рядків ======
void OutputSum()
{
	for (int i = 0; i < m; i++)
	{
		cout << ArraySum[i] << " ";
	}
	cout << endl;
}
//====== Функція перестановки ======
void replacement()
{
	int temp = 0;
	for (int i = 0; i < m - 1; i++)//перебір усіх елементів рядка
	{
		int min = ArraySum[i];//мінімальний елемент в масиві сум
		for (int j = i + 1; j < m; j++)
		{//знаходження мінімального елемента
			if (ArraySum[j] < min)
			{
				min = ArraySum[j];
				ArraySum[j] = ArraySum[i];
				ArraySum[i] = min;
				for (int k = 0; k < n; k++)//перестановка рядків
				{
					temp = array[j][k];
					array[j][k] = array[i][k];
					array[i][k] = temp;
				}
			}
		}
	}
}
//====== Головна функція ======
int main()
{
	cout << "laboratory work number 8 made by Anton Doroshenko, IS-52" << endl;
	cout << "enter n, m" << endl;
	cin >> m >> n;
	input();
	cout << "genereted array" << endl;
	output();
	SearchSum();
	cout << "sum of rows" << endl;
	OutputSum();
	replacement();
	cout << "new array" << endl;
	output();
	cout << "new sum of rows" << endl;
	OutputSum();
	system("pause");
}