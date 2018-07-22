#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
using namespace std;
const int inf = 1000000;
//======Ініціалізація стеку=====/
class Stack
{
	int info;
	Stack* next;
	Stack* current, *head;
public:
	Stack()
	{
		next = NULL;
		current = NULL;
		head = NULL;
	}
	void push(int value)
	{

		current = new(Stack);
		current->info = value;
		current->next = head;
		head = current;
	}
	int pop()
	{
		int value;
		current = head;
		value = current->info;
		head = current->next;
		delete current;
		return value;
	}
	int top()
	{
		int value;
		current = head;
		value = current->info;
		return value;
	}
	void show()
	{
		current = head;
		while (current != NULL)
		{
			cout << current->info + 1;
			if (current->next != 0)
				cout << " -> ";
			current = current->next;
		}
		cout << endl;
	}
	bool IsEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
};

//=====Функція зчитування матриці суміжності========//
void Read(FILE *f, int **C, char *filename, int m, int n)
{
	int a, b;
	f = fopen(filename, "r");
	fscanf(f, "%d%d", &a, &b);
	for (int i = 0; i<m; i++)
	{
		fscanf(f, "%d%d", &a, &b);
		C[a - 1][b - 1] = 1;
		C[b - 1][a - 1] = 1;
	}
}
//======Функція зчитування розмірності графу=======//
void Size(FILE* f, char *filename, int *m, int *n)
{
	cout << "Enter file name: " << endl;;
	cin >> filename;
	f = fopen(filename, "r");
	if (f != NULL)
	{
		cout << "File was succefully read! Enter any key to contunie...";
		fscanf(f, "%d%d", n, m);
	}
	_getch();
}
//=====Функція перевірки на цикл чи шлях======//
int Perev(int **C, int n)
{
	int num_even, num_odd, odd_ver;
	int *stepin = new int[n];
	num_even = 0;
	num_odd = 0;
	for (int i = 0; i<n; i++)
		stepin[i] = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (C[i][j] != 0 || C[i][j] != 0)
				stepin[i] += 1;
		}
	}
	for (int i = 0; i<n; i++)
	{
		if (stepin[i] % 2 == 0)
			num_even++;
		else
		{
			num_odd++;
			odd_ver = i;
		}
	}
	if (num_even == n)
		return -10;
	else if (num_odd == 2)
		return odd_ver;
	else
		return -20;
}
void InitializeVisit(int **C, int ** visit, int n)
{
	for (int i = 0; i<n; i++)
	for (int j = 0; j<n; j++)
	if (C[i][j] == 0)
		visit[i][j] = -1;
	else
		visit[i][j] = 0;
}
//===========Функція знаходження Ейлерових циклів======//
void EulerianCycle(int **visit, int n, int start)
{
	int cur, temp = 0;
	Stack tmp, res;

	cur = start;
	tmp.push(cur);

	while (!tmp.IsEmpty())
	{
		cur = tmp.top();
		for (int i = 0; i<n; i++)
		if (visit[cur][i] == 0)
		{
			visit[cur][i] = 1;
			visit[i][cur] = 1;
			tmp.push(i);
			break;
		}
		else if (i == n - 1)
		{
			temp = tmp.pop();
			res.push(temp);
		}
	}
	res.show();
}
//=======Головна функція========//
void main()
{
	int select, m, n, start, end, test;
	char filename[255];
	FILE *f = NULL;
	bool flag = true;
	int **C;
	int **visit;
	do
	{
		if (flag)
		{
			Size(f, filename, &m, &n);
			C = new int *[n];
			visit = new int *[n];
			for (int i = 0; i<n; i++)
			{
				C[i] = new int[n];
				visit[i] = new int[n];

			}
			for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
			{
				C[i][j] = 0;
				visit[i][j] = 0;
			}
			Read(f, C, filename, m, n);
			flag = false;
		}
		system("cls");
		cout << "Lab10 Anton Doroshenko" << endl;
		cout << "===============Menu================" << endl;
		cout << "  1.Eulerian cycle\n  2.Set new file\n  3.Exit" << endl;
		cout << "====================================" << endl;
		cout << "Enter item number: ";
		cin >> select;
		cout << endl;
		switch (select)
		{
		case 1:
			system("cls");
			InitializeVisit(C, visit, n);
			test = Perev(C, n);
			if (test == -10)
			{
				cout << "This graph contains eulerian cycle:" << endl;
				EulerianCycle(visit, n, 0);
			}
			else if (test == -20)
				cout << "This graph is not eulerian!" << endl;
			else
			{
				cout << "This graph contains eulerian path:" << endl;
				EulerianCycle(visit, n, test);
			}
			_getch();
			break;
		case 2:
			flag = true;
			break;
		}
	} while (select != 3);
}
