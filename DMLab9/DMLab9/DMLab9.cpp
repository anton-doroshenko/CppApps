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
	int MatrixH[100][100];      //матриця історій
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
//==For Jonson algorithm==
graph newGraph;
int h[100];
bool flag = true;
int dist[100][100];

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

//==For Floyd-Warshall algorithm==

void printResult()
{
	int arr[100];
	int i = endV - 1;
	int j = 0;
	while (i != startV - 1)
	{
		arr[j] = i;
		i = Graph.MatrixH[startV - 1][i] - 1;
		j++;
	}
	cout << startV;
	for (int k = (j - 1); k >= 0; k--)
	{
		cout << "->" << arr[k] + 1;
	}
	cout << endl;
}

void floyd()
{
	for (int p = 0; p < Graph.v; p++)
	{
		for (int r = 0; r < Graph.v; r++)
		{
			Graph.MatrixDis[p][r] = Graph.MatrixSecond[p][r];
			if (Graph.MatrixSecond[p][r] != inf)
			{
				Graph.MatrixH[p][r] = p + 1;
			}
			else
			{
				Graph.MatrixH[p][r] = 0;
			}
			if (p == r)
			{
				Graph.MatrixH[p][r] = 0;
			}
		}
	}
	bool flag = true;
	for (int k = 0; k < Graph.v; k++)
	{
		for (int i = 0; i < Graph.v; i++)
		{
			if (Graph.MatrixDis[i][k] != inf)
			{
				for (int j = 0; j < Graph.v; j++)
				{
					if (Graph.MatrixDis[i][j] > Graph.MatrixDis[i][k] + Graph.MatrixDis[k][j])
					{
						Graph.MatrixDis[i][j] = Graph.MatrixDis[i][k] + Graph.MatrixDis[k][j];
						Graph.MatrixH[i][j] = Graph.MatrixH[k][j];
					}
					if (i == j && Graph.MatrixDis[i][j] < 0)
					{
						flag = false;
						break;
					}
				}
				if (flag == false)
				{
					break;
				}
			}
		}
		if (flag == false)
		{
			break;
		}
	}
	if (flag)
	{
		for (int s = 0; s < Graph.v; s++)
		{
			for (int t = 0; t < Graph.v; t++)
			{
				if (Graph.MatrixDis[s][t] == inf)
				{
					cout << setw(3) << "-";
				}
				else
				{
					cout << setw(3) << Graph.MatrixDis[s][t];
				}
			}
			cout << endl;
		}
		cout << "Enter start vertex and finish vertex: " << endl;
		cin >> startV;
		cin >> endV;
		printResult();
	}
	else
	{
		cout << "There is negative cycle" << endl;
	}
}

//==For Jonson algorithm==
void createNewGraph()
{
	newGraph.v = Graph.v + 1;
	newGraph.u = Graph.u + Graph.v;
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			newGraph.MatrixSecond[i][j] = Graph.MatrixSecond[i][j];
		}
	}
	for (int k = 0; k < newGraph.v; k++)
	{
		newGraph.MatrixSecond[k][newGraph.v - 1] = inf;
		newGraph.MatrixSecond[newGraph.v - 1][k] = 0;
	}
}

void belmanFordAll(int start)
{
	flag = true;
	for (int i = 0; i < newGraph.v; i++)
	{
		way[i] = inf;
		for (int j = 0; j < newGraph.v; j++)
		{
			matrix[i][j] = inf;
		}
	}
	matrix[0][start - 1] = 0;
	for (int k = 1; k < newGraph.v; k++)
	{
		for (int l = 0; l < newGraph.v; l++)
		{
			matrix[k][l] = matrix[k - 1][l];
		}
		for (int m = 0; m < newGraph.v; m++)
		{
			for (int n = 0; n < newGraph.v; n++)
			{
				if (newGraph.MatrixSecond[m][n] != inf && matrix[k][n] > matrix[k - 1][m] + newGraph.MatrixSecond[m][n])
				{
					matrix[k][n] = matrix[k - 1][m] + newGraph.MatrixSecond[m][n];
					way[n] = m;
				}
			}
		}
	}
	for (int p = newGraph.v - 1; p < newGraph.v; p++)
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
				if (newGraph.MatrixSecond[m][n] != inf && matrix[p][n] > matrix[p][m] + newGraph.MatrixSecond[m][n])
				{
					flag = false;
					break;
				}
			}
		}
	}
	if (flag)
	{
		for (int r = 0; r < newGraph.v; r++)
		{
			//cout << "Vertex " << r + 1 << " - " << matrix[Graph.v - 1][r] << endl;
			h[r] = matrix[Graph.v - 1][r];
		}
	}
	else
	{
		cout << "There is negative cycle" << endl;
	}
}

void newWeight()
{
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			if (i == j)
			{
				Matrix[i][j] = 0;
			}
			else if (Graph.MatrixSecond[i][j] == inf)
			{
				Matrix[i][j] = inf;
			}
			else
			{
				Matrix[i][j] = Graph.MatrixSecond[i][j] + h[i] - h[j];
			}
		}
	}
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

void dijkstra(int start)
{
	int x = 0;
	int min;
	//start--;
	for (int i = 0; i < Graph.v; i++)
	{
		flags[i] = inf;
		color[i] = 0;
	}
	flags[start] = 0;
	color[start] = 1;
	for (int m = 0; m < Graph.v; m++)
	{
		dist[start][m] = flags[m];
	}
	x = start;
	while (notAll())
	{
		for (int j = 0; j < Graph.v; j++)
		{
			if ((color[j] == 0) && ((flags[x] + Matrix[x][j]) < flags[j]))
			{
				flags[j] = flags[x] + Matrix[x][j];
			}
		}
		for (int l = 0; l < Graph.v; l++)
		{
			dist[start][l] = flags[l];
		}
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

void distance()
{
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			Graph.MatrixDis[i][j] = dist[i][j] - h[i] + h[j];
		}
	}
}

void jonson()
{
	createNewGraph();
	belmanFordAll(newGraph.v);
	if (flag)
	{
		newWeight();
		for (int i = 0; i < Graph.v; i++)
		{
			dijkstra(i);
		}
		distance();
		for (int s = 0; s < Graph.v; s++)
		{
			for (int t = 0; t < Graph.v; t++)
			{
				if (Graph.MatrixDis[s][t] == inf)
				{
					cout << setw(3) << "-";
				}
				else
				{
					cout << setw(3) << Graph.MatrixDis[s][t];
				}
			}
			cout << endl;
		}
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
		cout << "1.Floyd-Warshall" << endl;
		cout << "2.Jonson" << endl;
		cout << "3.Exit" << endl;
		cout << "Enter your choose: ";
		cin >> key;
		switch (key)
		{
		case 1:{
				   floyd();
				   system("pause");
		};
			break;
		case 2:{
				   jonson();
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























