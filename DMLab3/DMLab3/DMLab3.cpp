#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int inf = -1;

struct graph
{
	int v = 0;                    //вершини графа
	int u = 0;                    //ребра графу
	int MatrixSecond[100][100];   //матриця суміжності
	int MatrixDis[100][100];      //матриця відстаней
	int MatrixAtt[100][100];      //матриця досяжності
};
int m;
int d;
bool CycleBeing, z;

graph Graph;
int Arr[2];
int Array[10];
FILE *f;
char FileName[100];
int Matrix[100][100];
int color[100];
int anc[100];
int Start;
int End;

void ReadNodesEdges()
{
	for (int i = 0; i < 2; i++)
	{
		fscanf(f, "%d", &Arr[i]);
	}
	Graph.v = Arr[0];
	Graph.u = Arr[1];
}

void MatrixSum()
{
	for (int i = 1; i <= Graph.u * 2; i++)
	{
		fscanf(f, "%d", &Array[(i - 1) % 2]);
		if ((i % 2) == 0)
		{
			Graph.MatrixSecond[Array[0] - 1][Array[1] - 1] = 1;
		}
	}
}

void OutputMatrixS()
{
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			cout << setw(2) << Graph.MatrixSecond[i][j];
		}
		cout << endl;
	}
}

void ReadFile()
{
	//cout << "Enter file name" << endl;
	//cin >> FileName;
	//f = fopen(FileName, "r");
	f = fopen("D:\\Study\\semestr2\\DM\\Task\\Task3\\graph_03_4.txt", "r");
	/*f = fopen("graph_03_1.txt", "r");*/
	if (f != NULL)
	{
		ReadNodesEdges();
		cout << Graph.v << " " << Graph.u << endl;
		MatrixSum();
		cout << "Second matrix" << endl;
		OutputMatrixS();
		system("pause");
	}
	else
	{
		cout << "File not open" << endl;
	}

	fclose(f);
}

void mult()
{
	int TempMat[100][100];
	int temp = 0;
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			temp = 0;
			for (int k = 0; k < Graph.v; k++)
			{
				temp = temp + Matrix[i][k] * Graph.MatrixSecond[k][j];
			}
			TempMat[i][j] = temp;
		}
	}
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			Matrix[i][j] = TempMat[i][j];
		}
	}
}

void OutputMatrixDis()
{
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			cout << setw(2) << Graph.MatrixDis[i][j];
		}
		cout << endl;
	}
}

void OutputMatrixAtt()
{
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			cout << setw(2) << Graph.MatrixAtt[i][j];
		}
		cout << endl;
	}
}

void DisAttMat()
{
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			Matrix[i][j] = Graph.MatrixSecond[i][j];
			if (Graph.MatrixSecond[i][j] == 0)
			{
				Graph.MatrixDis[i][j] = inf;
			}
			else
			{
				Graph.MatrixDis[i][j] = Graph.MatrixSecond[i][j];
			}
			if (i == j)
			{
				Graph.MatrixDis[i][j] = 0;
			}
		}
	}
	OutputMatrixDis();
	for (int i = 0; i < Graph.v - 1; i++)
	{
		mult();
		for (int j = 0; j < Graph.v; j++)
		{
			for (int k = 0; k < Graph.v; k++)
			{
				if (Graph.MatrixDis[j][k] == inf)
				{
					if (Matrix[j][k] != 0)
					{
						Graph.MatrixDis[j][k] = i + 2;
					}
				}
			}
		}
	}
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			if (Graph.MatrixDis[i][j] == inf)
			{
				Graph.MatrixAtt[i][j] = 0;
			}
			else
			{
				Graph.MatrixAtt[i][j] = 1;
			}
		}
	}
	cout << "Distance matrix is:" << endl;
	OutputMatrixDis();
	cout << "Attainability matrix is:" << endl;
	OutputMatrixAtt();
	system("pause");
}

void dfs(int x) 
{
	color[x] = 1;
	for (int i = 0; i < Graph.v; i++)
	{
		if (Graph.MatrixSecond[x][i] == 1)
		{
			int to = i;
			if (color[to] == 0)
			{
				anc[to] = x;
				dfs(to);
			}
			else if (color[to] == 1)
			{
				End = x;
				Start = to;
				int Cycle[100];
				Cycle[0] = Start;
				int i = 0;
				int k = End;
				while (k != Start)
				{
					i++;
					Cycle[i] = k;
					k = anc[k];
				}
				i++;
				Cycle[i] = Start;
				if (i > 2)
				{
					for (int j = i; j >= 0; j--)
					{
						cout << Cycle[j] + 1 << " ";
					}
					cout << endl;
				}
			}
		}
	}
	color[x] = 2;
}

void Cycle()
{

	for (int i = 0; i < Graph.v; i++)
	{
		anc[i] = -1;
		color[i] = 0;
	}
	Start = -1;
	for (int i = 0; i < Graph.v; i++)
	{
		dfs(i);
	}
	if (Start == -1)
	{
		cout << "Graph hasn`t cycles" << endl;
	}
	system("pause");
}

void Type()
{
	int Matrixx[100][100];
	bool Flag = true;
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			if (Graph.MatrixAtt[i][j] == 0)
			{
				Flag = false;
				break;
			}
		}
	}
	if (Flag == true)
	{
		cout << "Strongly linked" << endl;
	}
	else
	{
		int Temp[100][100];
		for (int i = 0; i < Graph.v; i++)
		{
			for (int j = 0; j < Graph.v; j++)
			{
				if (Graph.MatrixAtt[i][j] + Graph.MatrixAtt[j][i] == 0)
				{
					Temp[i][j] = 0;
				}
				else
				{
					Temp[i][j] = 1;
				}
			}
		}
		Flag = true;
		for (int i = 0; i < Graph.v; i++)
		{
			for (int j = 0; j < Graph.v; j++)
			{
				if (Temp[i][j] == 0)
				{
					Flag = false;
					break;
				}
			}
		}
		if (Flag == true)
		{
			cout << "Sided bound" << endl;
		}
		else
		{
			int Temporary[100][100];
			for (int i = 0; i < Graph.v; i++)
			{
				for (int j = 0; j < Graph.v; j++)
				{
					Temporary[i][j] = Graph.MatrixSecond[i][j] + Graph.MatrixSecond[j][i];
					if (i == j)
					{
						Temporary[i][j] += 1;
					}
					Matrixx[i][j] = Temporary[i][j];
				}
			}
			for (int i = 0; i < Graph.v - 1; i++)
			{
				int TempMat[100][100];
				int temp = 0;
				for (int i = 0; i < Graph.v; i++)
				{
					for (int j = 0; j < Graph.v; j++)
					{
						temp = 0;
						for (int k = 0; k < Graph.v; k++)
						{
							temp = temp + Matrixx[i][k] * Temporary[k][j];
						}
						TempMat[i][j] = temp;
					}
				}
				for (int i = 0; i < Graph.v; i++)
				{
					for (int j = 0; j < Graph.v; j++)
					{
						Matrixx[i][j] = TempMat[i][j];
						if (Matrixx[i][j] == 0)
						{
							Temp[i][j] = 0;
						}
						else
						{
							Temp[i][j] = 1;
						}
					}
				}
				Flag = true;
				for (int i = 0; i < Graph.v; i++)
				{
					for (int j = 0; j < Graph.v; j++)
					{
						if (Temp[i][j] == 0)
						{
							Flag = false;
							break;
						}
					}
				}
			}
			if (Flag == true)
			{
				cout << "Weakly bound" << endl;
			}
			else
			{
				cout << "Graph unattended" << endl;
			}
		}
	}
	system("pause");
}

int main()
{
	while (true)
	{
		system("cls");
		int key = 0;            //номер пункту меню
		cout << "Menu" << endl;
		cout << "1.Read data about graph from file" << endl;
		cout << "2.Output distance matrix and attainability matrix" << endl;
		cout << "3.Availability of simple cycles" << endl;
		cout << "4.Type of connectivity" << endl;
		cout << "5.Exit" << endl;
		cout << "Enter your choose: ";
		cin >> key;                 
		switch (key)
		{
		case 1: ReadFile();             
			break;
		case 2: DisAttMat();        
			break;
		case 3: Cycle();
			break;
		case 4:  Type();
			break;
		case 5: exit(0);
			break;
		default: cout << "Please, try again..." << endl;
			system("pause");
			break;
		}
	}
}