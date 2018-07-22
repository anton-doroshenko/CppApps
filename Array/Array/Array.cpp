#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
using namespace std;
FILE*f;
int m, n;
char filename[150] = "D:\\Study\\semestr2\\DM\\Task\\Task7\\graph_07_7.txt";
void OpenFile()
{
	/*puts("enter filename");
	cin >> filename;*/
	f = fopen(filename, "r");
	fscanf(f, "%d%d", &n, &m);
	if (f != NULL)
		puts("Ok");
	else
		cout << "file not find..." << endl;
	cout << "Enter any key to contunie..." << endl;
	_getch();
	fclose(f);
}
void Read(int * A, int * B, int**weight)
{
	f = fopen(filename, "r");
	fscanf(f, "%d%d", &n, &m);
	int cina;
	for (int i = 0; i<m; i++)
	{
		fscanf(f, "%d%d%d", &A[i], &B[i], &cina);
		weight[A[i] - 1][B[i] - 1] = cina;
	}
	fclose(f);
}
void BelmanAll(int*A, int*B, int**weight, int**l, int a)
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			l[i][j] = 99999;
		}
	}
	l[0][a - 1] = 0;
	for (int j = 1; j<n; j++)
	{
		for (int z = 1; z<n - 1; z++)
			l[j][z - 1] = l[j - 1][z - 1];
		for (int i = 0; i<m; i++)
		{
			if (l[j][B[i] - 1]>l[j - 1][A[i] - 1] + weight[A[i] - 1][B[i] - 1])
			{
				l[j][B[i] - 1] = l[j - 1][A[i] - 1] + weight[A[i] - 1][B[i] - 1];
			}
		}
	}
	int jj = 0;
	for (int z = 1; z<n + 1; z++)
	{
		int min = 99999;
		for (int i = 0; i<n; i++)
		{
			if (l[i][z - 1]<min)
			{
				min = l[i][z - 1];
				jj = i;
			}
		}
		if (min<9999)
			cout << min << "  ";
		else   cout << " - ";
	}
}
void All(int*A, int*B, int**weight, int**l, int**M)
{
	cout << "Input number of first vertex: ";
	int a;
	cin >> a;
	cout << endl;
	cout << "Lenght of shorterst route:" << endl;
	for (int i = 0; i<n; i++)
	{
		cout << "  " << i + 1;
	}
	cout << endl;
	cout << a << " ";
	BelmanAll(A, B, weight, l, a);
	cout << endl;
}
//=====Визначення найкоротшого шляху та маршруту============//
void Belman(int*A, int*B, int**weight, int**l, int**M)
{
	cout << "Input number of first vertex: ";  //введення першої вершини
	int a;  //перша вершина
	cin >> a;
	cout << endl;
	cout << "Input number of second vertex: ";  //введення першої вершини
	int z;  //друга вершина
	cin >> z;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			l[i][j] = 99999;
			M[i][j] = 0;
		}
	}
	l[0][a - 1] = 0;
	for (int j = 1; j<n - 1; j++)
	{
		for (int z = 1; z<n - 1; z++)
			l[j][z - 1] = l[j - 1][z - 1];
		for (int i = 0; i<m; i++)
		{
			if (l[j][B[i] - 1]>l[j - 1][A[i] - 1] + weight[A[i] - 1][B[i] - 1])
			{
				l[j][B[i] - 1] = l[j - 1][A[i] - 1] + weight[A[i] - 1][B[i] - 1];
				M[j][B[i] - 1] = A[i];
			}
		}
	}
	cout << endl;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	bool flag = true;
	for (int j = n - 1; j<n; j++)
	{
		for (int i = 0; i<m; i++)
		{
			if (l[j][B[i] - 1]>l[j][A[i] - 1] + weight[A[i] - 1][B[i] - 1])
			{
				cout << "The are minus cycle" << endl;
				flag = false;
				break;
			}
		}
	}
	int min = 99999;
	int jj = 0;
	for (int i = 0; i<n; i++)
	{
		if (l[i][z - 1]<min)
		{
			min = l[i][z - 1];
			jj = i;
		}
	}
	int lic = jj;
	if (flag)
	{
		if (min != 99999)
		{
			cout << "Lenght of shorterst route: " << min << endl;
			int * Way = new int[n];  //масив шляху
			for (int i = 0; i<n; i++)
				Way[i] = 0;
			while (jj != 0)
			{
				Way[jj] = z;
				z = M[jj][z - 1];
				jj--;
			}
			Way[jj] = a;
			for (int i = 0; i<lic + 1; i++)  //вивести шлях
			{
				cout << Way[i];
				if (i != lic)
					cout << " -> ";
			}
			cout << endl;
		}
		else  cout << "There is no way" << endl;  //вивести повідомлення
	}
}
void main()
{
	cout << "Input addres of file: " << endl;
	OpenFile();
	int*A = new int[m];
	int*B = new int[m];
	int**l = new int*[n];
	int**M = new int*[n];
	for (int i = 0; i<n; i++)
	{
		M[i] = new int[n];
		l[i] = new int[n];
	}
	int**weight = new int*[n];
	for (int i = 0; i<n; i++)
	{
		weight[i] = new int[n];
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			M[i][j] = 99999;
			l[i][j] = 99999;
		}
	}
	Read(A, B, weight);
	while (1)
	{
		cout << "Syaskiy Dmytro IS-32---LAB #8";
		cout << endl;
		cout << "==============================================================" << endl;
		cout << "1. Determine the shortest route between two vertices and its length." << endl;
		cout << "2. Determine the shortest distance from a given vertex to all other vertices." << endl;
		cout << "3. Exit" << endl;
		cout << "==============================================================" << endl;
		int key;
		cout << "Choosen menu item: " << endl;
		cin >> key;
		switch (key)
		{
		case 1: {Belman(A, B, weight, l, M); _getch(); break; }
		case 2: {All(A, B, weight, l, M); _getch(); break; }
		case 3: { exit(0); break; }
		default: {cout << "Error" << endl; break; }
		}
	}
	system("pause");
	_getch();
}


