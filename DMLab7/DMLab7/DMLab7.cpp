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
int t = 0;
int startV = 0;
int endV = 0;
bool negative = false;

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
			if (weight < 0)
			{
				negative = true;
			}
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
	f = fopen("D:\\Study\\semestr2\\DM\\Task\\Task7\\graph_07_5.txt", "r");
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

void dijkstra()
{
	int x = 0;
	int min;
	cout << "Enter start vertex: " << endl;
	cin >> startV;
	startV--;
	cout << "Enter end vertex: " << endl;
	cin >> endV;
	endV--;
	for (int i = 0; i < Graph.v; i++)
	{
		flags[i] = inf;
		color[i] = 0;
	}
	flags[startV] = 0;
	color[startV] = 1;
	cout << setw(3) << " ";
	for (int m = 0; m < Graph.v; m++)
	{
		if (flags[m] == inf)
		{
			cout << setw(3) << "-";
		}
		else
		{
			cout << setw(3) << flags[m];
		}
	}
	cout << endl;
	x = startV;
	while (color[endV] == 0)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			if ((color[j] == 0) && ((flags[x] + Graph.MatrixSecond[x][j]) < flags[j]))
			{
				flags[j] = flags[x] + Graph.MatrixSecond[x][j];
				way[j] = x;
			}
		}
		cout << setw(3) << x + 1;
		for (int l = 0; l < Graph.v; l++)
		{
			if (flags[l] == inf)
			{
				cout << setw(3) << "-";
			}
			else
			{
				cout << setw(3) << flags[l];
			}
		}
		cout << endl;
		min = inf;
		for (int k = 0; k < Graph.v; k++)
		{
			if ((color[k] == 0) && (flags[k] < min))
			{
				min = flags[k];
				x = k;
			}
		}
		if (min == inf)
		{
			cout << "There are not way" << endl;
			system("pause");
			exit(1);
		}
		else
		{
			color[x] = 1;
		}
	}
}

void printResult()
{
	int arr[100];
	int i = endV;
	int j = 0;
	while (i != startV)
	{
		arr[j] = i;
		i = way[i];
		j++;
	}
	cout << startV + 1;
	for (int k = (j - 1); k >= 0; k--)
	{
		cout << "->" << arr[k] + 1;
	}
	cout << endl;
}

bool notAll()
{
	for (int i = 0; i < Graph.v; i++)
	{
		if (color[i] == 0)
		{
			return true;
		}
	}
	return false;
}

void waysFromNode()
{
	int x = 0;
	int min;
	cout << "Enter start vertex: " << endl;
	cin >> startV;
	startV--;
	for (int i = 0; i < Graph.v; i++)
	{
		flags[i] = inf;
		color[i] = 0;
	}
	flags[startV] = 0;
	color[startV] = 1;
	cout << setw(3) << " ";
	for (int m = 0; m < Graph.v; m++)
	{
		if (flags[m] == inf)
		{
			cout << setw(3) << "-";
		}
		else
		{
			cout << setw(3) << flags[m];
		}
	}
	cout << endl;
	x = startV;
	while (notAll())
	{
		for (int j = 0; j < Graph.v; j++)
		{
			if ((color[j] == 0) && ((flags[x] + Graph.MatrixSecond[x][j]) < flags[j]))
			{
				flags[j] = flags[x] + Graph.MatrixSecond[x][j];
			}
		}
		cout << setw(3) << x + 1;
		for (int l = 0; l < Graph.v; l++)
		{
			if (flags[l] == inf)
			{
				cout << setw(3) << "-";
			}
			else
			{
				cout << setw(3) << flags[l];
			}
		}
		cout << endl;
		min = inf;
		for (int k = 0; k < Graph.v; k++)
		{
			if ((color[k] == 0) && (flags[k] < min))
			{
				min = flags[k];
				x = k;
			}
		}
		if (min == inf)
		{
			//cout << "There are not way" << endl;
			//system("pause");
			break;
		}
		else
		{
			color[x] = 1;
		}
	}
}

void outputResult()
{
	for (int i = 0; i < Graph.v; i++)
	{
		cout<< "Vertex " << i + 1 << " - " << flags[i] << endl;
	}
}

int main()
{
	ReadFile();
	if (negative)
	{
		system("cls");
		cout << "Dijkstra algorithm can`t working" << endl;
		system("pause");
		exit(1);
	}
	while (true)
	{
		system("cls");
		int key = 0;            //номер пункту меню
		cout << "Menu" << endl;
		cout << "1.Dijkstra for two vertex" << endl;
		cout << "2.Ways from one vertex to another" << endl;
		cout << "3.Exit" << endl;
		cout << "Enter your choose: ";
		cin >> key;
		switch (key)
		{
		case 1:{
				   dijkstra();
				   printResult();
				   system("pause");
		};
			break;
		case 2:{
				   waysFromNode();
				   outputResult();
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