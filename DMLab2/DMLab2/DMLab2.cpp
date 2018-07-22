#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <iomanip>

using namespace std;

const int inf = 1000;

struct graph
{
	int v = 0;                    //вершини графа
	int u = 0;                    //ребра графу
	int MatrixFirst[200][200];
	int MatrixSecond[100][100];
	int Legth[100][100];
	int History[100][100];
	int outdegree[100];
	int indegree[100];
	int degree[100];
	int Excentr[100];
	int Diametr = 0;
	int radius = inf;
	int centr;
	bool regular = true;
};

graph Graph;
int Arr[5];
int Array[10];
int x, temp;
FILE *f;
char FileName[100];

void ReadFile()
{
	for (int i = 0; i < 2; i++)
	{
		fscanf(f, "%d", &Arr[i]);
	}
	Graph.v = Arr[0];
	Graph.u = Arr[1];
}

void  MatrixInc()
{
	for (int i = 1; i <= Graph.u * 2; i++)
	{
		fscanf(f, "%d", &x);
		if (i % 2 != 0)
		{
			Graph.MatrixFirst[x - 1][i / 2] = -1;
			temp = x;
		}
		else
		{
			if (temp == x)
			{
				Graph.MatrixFirst[temp - 1][(i - 1) / 2] = 2;
			}
			else
			{
				Graph.MatrixFirst[x - 1][(i - 1) / 2] = 1;
			}
		}
	}
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

void OutputMatrixF()
{
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.u; j++)
		{
			cout << setw(2) << Graph.MatrixFirst[i][j];
		}
		cout << endl;
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

void SearchInOutDegrees()
{
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			Graph.indegree[i] += Graph.MatrixSecond[i][j];
			Graph.outdegree[i] += Graph.MatrixSecond[j][i];
		}
	}
}

void SearchDegree()
{
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.u; j++)
		{
			if (Graph.MatrixFirst[i][j] == 2)
			{
				Graph.degree[i] += 2;
			}
			else if (Graph.MatrixFirst[i][j] != 0)
			{
				Graph.degree[i] += 1;
			}
		}
	}
}
void Regular()
{
	for (int i = 0; i < Graph.v; i++)
	{
		if (Graph.degree[i] != Graph.degree[0])
		{
			Graph.regular = false;
			break;
		}
	}
}

void Isolate()
{
	for (int i = 0; i < Graph.v; i++)
	{
		if (Graph.degree[i] == 0)
		{
			cout << "v" << i + 1 << " is isolate" << endl;
		}
		if (Graph.degree[i] == 1)
		{
			cout << "v" << i + 1 << " is hanging" << endl;
		}
	}
}

void OutPutDegrees()
{
	for (int i = 0; i < Graph.v; i++)
	{
		cout << "Indegree of v" << i + 1 << " is " << Graph.indegree[i] << endl;
		cout << "Outdegree of v" << i + 1 << " is " << Graph.outdegree[i] << endl;
		cout << "d(v" << i + 1 << ") is " << Graph.degree[i] << endl;
		cout << endl;
	}
	if (Graph.regular == true)
	{
		cout << "Graph is regular" << endl;
		cout << "Graph degree is" << Graph.degree[0] << endl;
	}
	else
	{
		cout << "Graph is not regular" << endl;
	}
}

void MinLegth()
{
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			if (Graph.MatrixSecond[i][j] == 0)
			{
				Graph.Legth[i][j] = inf;
			}
			else
			{
				Graph.Legth[i][j] = Graph.MatrixSecond[i][j];
			}
		}
	}
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			if (Graph.Legth[i][j] != inf)
			{
				for (int k = 0; k < Graph.v; k++)
				{
					if (Graph.Legth[i][k] > Graph.Legth[i][j] + Graph.Legth[j][k])
					{
						Graph.Legth[i][k] = Graph.Legth[i][j] + Graph.Legth[j][k];
					}
				}
			}
		}
	}
}

void OutLegth()
{
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			if (Graph.Legth[i][j] > Graph.Diametr && Graph.Legth[i][j] != inf)
			{
				Graph.Diametr = Graph.Legth[i][j];
			}
			cout << Graph.Legth[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Diametr is " << Graph.Diametr << endl;
}

void Radius()
{
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			if (Graph.Excentr[i] < Graph.Legth[i][j] && Graph.Legth[i][j] != inf)
			{
				Graph.Excentr[i] = Graph.Legth[i][j];
			}
		}
	}
	for (int k = 0; k < Graph.v; k++)
	{
		if (Graph.Excentr[k] < Graph.radius)
		{
			Graph.radius = Graph.Excentr[k];
		}
	}
	cout << "Radius is " << Graph.radius << endl;
	for (int l = 0; l < Graph.v; l++)
	{
		if (Graph.Excentr[l] == Graph.radius)
		{
			cout << "v" << l + 1 << " is centr" << endl;
		}
	}
}

void Yarus()
{
	int n = 0;
	for (int i = 0; i < Graph.v; i++)
	{
		//n = Graph.Legth[i][0];
		//cout << "D(v" << i + 1 << ", " << n << "):" << endl;
		for (int j = 0; j < Graph.v; j++)
		{
			if (Graph.Legth[i][j] != inf)
			{
				n = Graph.Legth[i][j];
				cout << "D(v" << i + 1 << ", " << n << "):" << endl;
				for (int k = j; k < Graph.v; k++)
				{
					if (Graph.Legth[i][k] == n)
					{
						cout << "v" << k + 1 << endl;
						Graph.Legth[i][k] = inf;
					}
				}
			}
		}
	}
}

int main()
{
	/*cout << "Enter file name" << endl;
	gets(FileName);*/
	f = fopen("D:\\Study\\semestr2\\DM\\Task\\Task2\\graph_01_5.txt", "r");
	if (f != NULL)
	{
		ReadFile();
		cout << Graph.v << " " << Graph.u << endl;
		MatrixInc();
		cout << "First matrix" << endl;
		OutputMatrixF();
	}
	else
	{
		cout << "File not open" << endl;
	}

	fclose(f);
	f = fopen("D:\\Study\\semestr2\\DM\\Task\\Task2\\graph_01_5.txt", "r");
	if (f != NULL)
	{
		ReadFile();
		MatrixSum();
		cout << "Second matrix" << endl;
		OutputMatrixS();
	}
	else
	{
		cout << "File not open" << endl;
	}
	fclose(f);
	SearchInOutDegrees();
	SearchDegree();
	Regular();
	OutPutDegrees();
	Isolate();
	MinLegth();
	OutLegth();
	Radius();
	Yarus();
	system("pause");
}