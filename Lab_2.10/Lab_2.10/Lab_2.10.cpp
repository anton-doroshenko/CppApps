//Laboratory work
//written by student of the first curse
//of the group IC-52
//Anton Doroshenko
//2016.05.04
//==========================================================================

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;
int numberOfVertexs,				//кількість магазинів
numberOfRibs,						//кількість ребер
listOfRibs[6000][3],				//масив ребер з їх довжинами
numbersOfRibsForMinDistWay[300],	//номери ребер, що входять до мінімального шляху
arrForConnectednessOfGraph[100],	//масив для превірки зв'язності  
minDist,							//мінімальна довжина прокладки лінії зв'язку
amountOfRibsInMinDistWay;			//кількість ребер в мінмальному шляху прокладки
bool resOfCheck[6000];					//масив для запам'ятовування зв'язний граф чи ні в можливих других по мінімальності шляхів

//============ перевірка графа на зв'зність =============
int Check()
{
	bool f=true;
	for (int i = 1; i < numberOfVertexs; i++)
	{
		if (arrForConnectednessOfGraph[0] != arrForConnectednessOfGraph[i])
		{
			f = false;
			break;
		}
	}
	return f;
}
//===================== сортування рядків масиву по неспаданню елементів в третьому стовпці ====================
void Sort(int a[][3], int left, int right)
{
	int l = left;
	int r = right;
	int tmp = 0;
	int mid = a[r][2];
	while (l <= r)
	{
		while ((a[l][2] < mid) && (l <= right))
		{
			l++;
		}
		while ((a[r][2] > mid) && (r >= left))
		{
			r--;
		}
		if (l <= r)
		{
			for (int i = 0; i < 3; i++)
			{
				
				tmp = a[l][i];
				a[l][i] = a[r][i];
				a[r][i] = tmp;
			}
			l++;
			r--;
		}
	}
	if (r > left)
	{
		Sort(a, left, r);
	}
	if (l < right)
	{
		Sort(a, l, right);
	}
}
//======== задання початкових значень в масиві для перевірки зв'язності ========
void ResetConection()
{
	for (int i = 0; i <= numberOfVertexs; i++)
	{
		arrForConnectednessOfGraph[i] = i;
	}
}
//=============== знаходження мінімальної відстані ==================
void MinimalDistance()
{
	int u = 0;
	for (int i = 0; i < numberOfRibs; i++)
	{
		if (arrForConnectednessOfGraph[listOfRibs[i][0]] != arrForConnectednessOfGraph[listOfRibs[i][1]])
		{
			minDist += listOfRibs[i][2];
			numbersOfRibsForMinDistWay[u] = i;
			u++;
			
			int col = arrForConnectednessOfGraph[listOfRibs[i][0]];
			for (int j = 0; j < numberOfVertexs; j++)
			{
				if (arrForConnectednessOfGraph[j] == col)
				{
					arrForConnectednessOfGraph[j] = arrForConnectednessOfGraph[listOfRibs[i][1]];;
				}
			}
		}
	}
	amountOfRibsInMinDistWay = u;
}
//================================ введення данних =====================================
void Input()
{
	cout << "Enter number of vertex end edges:" << endl;
	cin >> numberOfVertexs >> numberOfRibs;
	cout << "Enter list of edges:" << endl;
	for (int i = 0; i < numberOfRibs; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> listOfRibs[i][j];
		}
	}
}
void Output()
{
	if (Check())
	{
		cout << "Dovguna minimal'noyi zv'aznoyi meregi: ";
		cout << minDist << endl;
		cout << "Kil'kist' reber y minimal'niy meregi: ";
		cout << amountOfRibsInMinDistWay << endl;
		cout << "Paru magazuniv mig yakumu potribno proklastu meregy" << endl;
		for (int i = 0; i < amountOfRibsInMinDistWay; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << setw(3) << listOfRibs[numbersOfRibsForMinDistWay[i]][j];
			}
			cout << endl;
		}
	}
	else
		cout << "Nemogluvo proklastu meregy, schob ysi magazunu bylu zvyazani" << endl;
}
//==================== головна функція =====================
int main()
{
	Input();
	Sort(listOfRibs, 0, numberOfRibs - 1);
	ResetConection();
	MinimalDistance();
	Output();
	system("pause");
}