#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int matrix[20][20];  //задана квадратна матриця
int n = 0;           //кількість рядків (стовпців)
int ArrayTop[100];
int ArrayBottom[100];
int legth = 0;
int Legth = 0;

void CreateMatrix()
{
	srand((unsigned)(time(NULL)));
	cout << "Enter number of rows (colums)" << endl;
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
void Replacement()
{
	for (int i = 0; i < n - i; i++)
	{
		for (int j = i; j < n - i; j++)
		{
			ArrayTop[legth] = matrix[i][j];
			legth++;
			Legth = legth;
		}
	}
	legth = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j >= n - i - 1; j--)
		{
			ArrayBottom[legth] = matrix[i][j];
			legth++;
		}
	}
}
void OutputArray(int Array[], int legth)
{
	for (int i = 0; i < legth; i++)
	{
		cout << Array[i] << ' ';
	}
	cout << endl;
}
int main()
{
	CreateMatrix();
	cout << "Your matrix is:" << endl;
	OutputMatrix();
	Replacement();
	OutputArray(ArrayTop, Legth);
	OutputArray(ArrayBottom, Legth);
	cout << "New matrix is:" << endl;
	OutputMatrix();
	system("pause");
}