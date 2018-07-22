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

struct Item
{
	int data;
	Item* next;
};

Item *head, *curr;
Item* last = NULL;

graph Graph;
int Arr[2];
int Array[10];
FILE *f;
char FileName[100];
int Matrix[100][100];
int N = 0;
int* PtrN = &N;
int color[100];
int dfs[100];
int bfs[100];

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

void push(int* value)
{
	curr = new(Item);
	curr->data = *value;
	curr->next = head;
	head = curr;
}

void pop()
{
	curr = head;
	head = curr->next;
	delete curr;
}

void add(int* Node)
{
	curr = new Item;
	curr->data = *Node;
	curr->next = NULL;
	if (last == NULL)
	{
		head = curr;
	}
	else
	{
		last->next = curr;
	}
	last = curr;
}

void del()
{
	curr = head;
	//*value = head->data;
	head = curr->next;
	if (head == NULL)
	{
		last = NULL;
	}
	delete curr;
}

void outSt(bool Flag, int Node)
{
	int L;
	int* ptrL = &L;
	int Arr[100];
	int i = 0;
	while (head != 0)
	{
		Arr[i] = head->data;
		i++;
		pop();
	}
	for (int j = i - 1; j >= 0; j--)
	{
		L = Arr[j];
		push(ptrL);
	}
	if (Flag == true)
	{
		cout << "  " << Node + 1 << "               " << dfs[Node] << "               ";
		for (int k = 0; k < i; k++)
		{
			cout << Arr[k] + 1 << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "  " << 0 << "               " << 0 << "               ";
		for (int k = 0; k < i; k++)
		{
			cout << Arr[k] + 1 << " ";
		}
		cout << endl;
	}
}

void outQ(bool Flag, int Node)
{
	int L;
	int* ptrL = &L;
	int Arr[100];
	int i = 0;
	while (head != 0)
	{
		Arr[i] = head->data;
		i++;
		del();
	}
	for (int j = 0; j < i; j++)
	{
		L = Arr[j];
		add(ptrL);
	}
	if (Flag == true)
	{
		cout << "  " << Node + 1 << "               " << bfs[Node] << "               ";
		for (int k = 0; k < i; k++)
		{
			cout << Arr[k] + 1 << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "  " << 0 << "               " << 0 << "               ";
		for (int k = 0; k < i; k++)
		{
			cout << Arr[k] + 1 << " ";
		}
		cout << endl;
	}
}

void DFS()
{
	int Ver;
	int* ptrVer = &Ver;
	bool flag = false;
	bool flag2 = false;
	cout << "Enter v" << endl;
	cin >> N;
	N--;
	color[N] = 1;
	dfs[N] = 1;
	cout << "  Node          DFS number          Stack" << endl;
	cout << "== == == == == == == == == == == == == == == ==" << endl;
	cout << "  " << N + 1 << "               " << dfs[N] << "               " << N + 1 << endl;
	push(PtrN);
	int k = 1;
	while (head != 0)
	{
		flag = false;
		Ver = head->data;
		for (int i = 0; i < Graph.v; i++)
		{
			int* ptrI = &i;
			if (Graph.MatrixSecond[Ver][i] != 0 && color[i] == 0)
			{
				k++;
				color[i] = 1;
				dfs[i] = k;
				push(ptrI);
				flag = true;
				outSt(flag, i);
				break;
			}
		}
		if (flag == false)
		{
			pop();
			outSt(flag, Ver);
		}
	}
	for (int m = 0; m < Graph.v; m++)
	{
		color[m] = 0;
		dfs[m] = 0;
	}
	system("pause");
}

void BFS()
{
	int Ver;
	int* ptrVer = &Ver;
	bool flag = false;
	bool flag2 = false;
	cout << "Enter v" << endl;
	cin >> N;
	N--;
	color[N] = 1;
	bfs[N] = 1;
	cout << "  Node          BFS number          Queue" << endl;
	cout << "== == == == == == == == == == == == == == == ==" << endl;
	cout << "  " << N + 1 << "               " << bfs[N] << "               " << N + 1 << endl;
	add(PtrN);
	int k = 1;
	while (head != 0)
	{
		flag = false;
		Ver = head->data;
		for (int i = 0; i < Graph.v; i++)
		{
			int* ptrI = &i;
			if (Graph.MatrixSecond[Ver][i] != 0 && color[i] == 0)
			{
				k++;
				color[i] = 1;
				bfs[i] = k;
				add(ptrI);
				flag = true;
				outQ(flag, i);
				//outSt(flag, i);
			}
		}
		del();
		flag = false;
		outQ(flag, Ver);
		/*if (flag == false)
		{
			pop();
			outSt(flag, Ver);
		}*/
	}
	for (int m = 0; m < Graph.v; m++)
	{
		color[m] = 0;
		dfs[m] = 0;
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
		cout << "2.DFS" << endl;
		cout << "3.BFS" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter your choose: ";
		cin >> key;
		switch (key)
		{
		case 1: ReadFile();
			break;
		case 2: DFS();
			break;
		case 3: BFS();
			break;
		case 4: exit(0);
			break;
		default: cout << "Please, try again..." << endl;
			system("pause");
			break;
		}
	}
}
