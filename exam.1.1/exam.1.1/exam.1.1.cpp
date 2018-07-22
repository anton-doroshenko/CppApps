#include <iostream>
#include <stdlib.h>
#include <time.h>

int matrix[50][50];  //задана квадратна матриця
int n = 0;           //кількість рядків і стовпців матриці
int MaxEl = 0;       //максимальний елемент виділеної області

using namespace std;

void CreateMatrix()
{
	srand((unsigned)(time(NULL)));
	cout << "Enter number of rows and colums" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 30;
		}
	}
}
void OutputMatrix()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}
void SearchMaxElement()
{
	MaxEl = matrix[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n - i; j++)
		{
			if (MaxEl < matrix[i][j])
			{
				MaxEl = matrix[i][j];
			}
		}
	}
}
void Replacement()
{
	for (int i = n; i >= 1; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			matrix[i][j] = MaxEl;
		}
	}
	for (int i = n; i >= 1; i--)
	{
		for (int j = n - i; j < n; j++)
		{
			matrix[i][j] = MaxEl;
		}
	}
}

int main()
{
	CreateMatrix();
	cout << "Your matrix is:" << endl;
	OutputMatrix();
	SearchMaxElement();
	cout << "Max element is: " << MaxEl << endl;
	Replacement();
	cout << "New matrix is:" << endl;
	OutputMatrix();
	system("pause");
}