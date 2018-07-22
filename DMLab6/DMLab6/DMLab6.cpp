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

graph Graph;
int Arr[2];
int Array[10];
FILE *f;
char FileName[100];
int Matrix[100][100];
int N = 0;
int* PtrN = &N;
int color[100];
int ft[100];
int t = 0;

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
	f = fopen("D:\\Study\\semestr2\\DM\\Task\\Task6\\graph_06_5.txt", "r");
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

void dfsr(int Node)
{
	color[Node] = 1;
	for (int k = 0; k < Graph.v; k++)
	{
		if (Graph.MatrixSecond[Node][k] == 1 && color[k] == 0)
		{
			dfsr(k);
		}
	}
	t++;
	ft[t - 1] = Node + 1;
}

void dfsr2(int Node)
{
	cout << Node + 1 << " ";
	color[Node] = 1;
	for (int k = 0; k < Graph.v; k++)
	{
		if (Matrix[Node][k] == 1 && color[k] == 0)
		{
			dfsr2(k);
		}
	}
}

void dfsLoop()
{
	for (int i = 0; i < Graph.v; i++)
	{
		color[i] = 0;
	}
	t = 0;
	for (int j = 0; j < Graph.v; j++)
	{
		if (color[j] == 0)
		{
			dfsr(j);
		}
	}
}

void dfsLoop2()
{
	for (int i = 0; i < Graph.v; i++)
	{
		color[i] = 0;
	}
	t = 0;
	for (int j = Graph.v - 1; j >= 0; j--)
	{
		if (color[ft[j] - 1] == 0)
		{
			dfsr2(ft[j] - 1);
			cout << endl;
			N++;
		}
	}
}

void StrConComp()
{
	dfsLoop();
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			Matrix[j][i] = Graph.MatrixSecond[i][j];
		}
	}
	dfsLoop2();
	cout << "Number of conections: " << N << endl;
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
		cout << "2.Strongly Conect Components" << endl;
		cout << "3.Exit" << endl;
		cout << "Enter your choose: ";
		cin >> key;
		switch (key)
		{
		case 1: ReadFile();
			break;
		case 2: StrConComp();
			break;
		case 3: exit(0);
			break;
		default: cout << "Please, try again..." << endl;
			system("pause");
			break;
		}
	}
}