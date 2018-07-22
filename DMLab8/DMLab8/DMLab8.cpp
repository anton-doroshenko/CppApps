#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int inf = 1000;

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
int weight = 0;
FILE *f;
char FileName[100];
int Matrix[100][100];
int N = 0;
int* PtrN = &N;
int color[100];
int flags[100];
int way[100];
int matrix[100][100];
int t = 0;
int startV = 0;
int endV = 0;

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
	for (int j = 0; j < Graph.v; j++)
	{
		for (int k = 0; k < Graph.v; k++)
		{
			if (j == k)
			{
				Graph.MatrixSecond[j][k] = 0;
			}
			else
			{
				Graph.MatrixSecond[j][k] = inf;
			}
		}
	}
	for (int i = 1; i <= Graph.u * 2; i++)
	{
		fscanf(f, "%d", &Array[(i - 1) % 2]);
		if ((i % 2) == 0)
		{
			fscanf(f, "%d", &weight);
			Graph.MatrixSecond[Array[0] - 1][Array[1] - 1] = weight;
		}
	}
}

void OutputMatrixS()
{
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			if (Graph.MatrixSecond[i][j] == inf)
			{
				cout << setw(3) << "-";
			}
			else
			{
				cout << setw(3) << Graph.MatrixSecond[i][j];
			}
		}
		cout << endl;
	}
}

void ReadFile()
{
	//cout << "Enter file name" << endl;
	//cin >> FileName;
	//f = fopen(FileName, "r");
	f = fopen("D:\\Study\\semestr2\\DM\\Task\\Task7\\graph_07_7.txt", "r");
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

void printResult()
{
	int arr[100];
	int i = endV - 1;
	int j = 0;
	while (i != startV - 1)
	{
		arr[j] = i;
		i = way[i];
		j++;
	}
	cout << startV;
	for (int k = (j - 1); k >= 0; k--)
	{
		cout << "->" << arr[k] + 1;
	}
	cout << endl;
}

void belmanFordAll()
{
	bool flag = true;
	cout << "Enter start vertex: " << endl;
	cin >> startV;
	for (int i = 0; i < Graph.v; i++)
	{
		way[i] = inf;
		for (int j = 0; j < Graph.v; j++)
		{
			matrix[i][j] = inf;
		}
	}
	matrix[0][startV - 1] = 0;
	for (int k = 1; k < Graph.v; k++)
	{
		for (int l = 0; l < Graph.v; l++)
		{
			matrix[k][l] = matrix[k - 1][l];
		}
		for (int m = 0; m < Graph.v; m++)
		{
			for (int n = 0; n < Graph.v; n++)
			{
				if (Graph.MatrixSecond[m][n] != inf && matrix[k][n] > matrix[k - 1][m] + Graph.MatrixSecond[m][n])
				{
					matrix[k][n] = matrix[k - 1][m] + Graph.MatrixSecond[m][n];
					way[n] = m;
				}
			}
		}
	}
	for (int p = Graph.v - 1; p < Graph.v; p++)
	{
		if (!flag)
		{
			break;
		}
		for (int m = 0; m < Graph.v; m++)
		{
			if (!flag)
			{
				break;
			}
			for (int n = 0; n < Graph.v; n++)
			{
				if (Graph.MatrixSecond[m][n] != inf && matrix[p][n] > matrix[p][m] + Graph.MatrixSecond[m][n])
				{
					flag = false;
					break;
				}
			}
		}
	}
	if (flag)
	{
		for (int r = 0; r < Graph.v; r++)
		{
			cout << "Vertex " << r + 1 << " - " << matrix[Graph.v - 1][r] << endl;
		}
	}
	else
	{
		cout << "There is negative cycle" << endl;
	}
}

void belmanFordWay()
{
	bool flag = true;
	cout << "Enter start vertex and finish vertex: " << endl;
	cin >> startV;
	cin >> endV;
	for (int i = 0; i < Graph.v; i++)
	{
		way[i] = inf;
		for (int j = 0; j < Graph.v; j++)
		{
			matrix[i][j] = inf;
		}
	}
	matrix[0][startV - 1] = 0;
	for (int k = 1; k < Graph.v; k++)
	{
		for (int l = 0; l < Graph.v; l++)
		{
			matrix[k][l] = matrix[k - 1][l];
		}
		for (int m = 0; m < Graph.v; m++)
		{
			for (int n = 0; n < Graph.v; n++)
			{
				if (Graph.MatrixSecond[m][n] != inf && matrix[k][n] > matrix[k - 1][m] + Graph.MatrixSecond[m][n])
				{
					matrix[k][n] = matrix[k - 1][m] + Graph.MatrixSecond[m][n];
					way[n] = m;
				}
			}
		}
		for (int s = 0; s < Graph.v; s++)
		{
			if (way[s] == inf)
			{
				cout << "- ";
			}
			else
			{
				cout << way[s] + 1 << " ";
			}
		}
		cout << endl;
	}
	for (int p = Graph.v - 1; p < Graph.v; p++)
	{
		if (!flag)
		{
			break;
		}
		for (int m = 0; m < Graph.v; m++)
		{
			if (!flag)
			{
				break;
			}
			for (int n = 0; n < Graph.v; n++)
			{
				if (Graph.MatrixSecond[m][n] != inf && matrix[p][n] > matrix[p][m] + Graph.MatrixSecond[m][n])
				{
					flag = false;
					break;
				}
			}
		}
	}
	if (flag)
	{
		printResult();
	}
	else
	{
		cout << "There is negative cycle" << endl;
	}
}

int main()
{
	ReadFile();
	while (true)
	{
		system("cls");
		int key = 0;            //номер пункту меню
		cout << "Menu" << endl;
		cout << "1.Belman - Ford for all vertex" << endl;
		cout << "2.Way from one vertex to another" << endl;
		cout << "3.Exit" << endl;
		cout << "Enter your choose: ";
		cin >> key;
		switch (key)
		{
		case 1:{
				   belmanFordAll();
				   system("pause");
		};
			break;
		case 2:{
				   belmanFordWay();
				   system("pause");
		};
			break;
		case 3: exit(0);
			break;
		default: cout << "Please, try again..." << endl;
			system("pause");
			break;
		}
	}
}