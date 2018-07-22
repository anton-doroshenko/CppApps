#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<stack>
#include<queue>
#include<conio.h>
using namespace std;
stack <int> s;
queue <int> q;
FILE*f;
int m, n;
bool fgf;
int mm;
char filename[100] = "D:\\Study\\semestr2\\DM\\Task\\Task2\\graph_01_4.txt";
void OpenFile();
void DFS(int**D);
void BFS(int**D);
void Read(int * A, int * B, int ** D);
void output(stack <int> s, bool l, int*dfs)
{
	int y = s.size();  //розмір стеку
	int *g = new int[s.size()];  //створити масив
	int i = 0;
	while (!(s.empty())) //поки стек не пустий
	{
		g[i] = s.top(); //записати елемент масиву
		s.pop(); //стерти елемент стеку
		i++;  //збільшити лічильник
	}
	if (!l)
		cout << "   " << g[0] + 1 << "          " << dfs[g[0]] << "           ";
	else
		cout << "   " << 0 << "          " << 0 << "           ";
	for (int i = y - 1; i >= 0; i--) //починаючи з кінця 
		cout << g[i] + 1 << " "; //вивести елементи циклу
	cout << endl;
	for (int i = 0; i<y; i++) //починаючи з кінця 
		s.push(g[i]);
}
void outputs(queue <int> q, bool l, int*bfs)
{
	int y = q.size();  //розмір 
	int *g = new int[q.size()];  //створити масив
	int i = 0;
	while (!(q.empty())) //поки  не пустий
	{
		g[i] = q.front(); //записати елемент масиву
		q.pop(); //стерти елемент стеку
		i++;  //збільшити лічильник
	}
	if (!l)
		cout << "   " << g[y - 1] + 1 << "          " << bfs[g[y - 1]] << "           ";
	else
		cout << "   " << 0 << "          " << 0 << "           ";
	for (int i = 0; i<y; i++)
		cout << g[i] + 1 << " "; //вивести елементи 
	cout << endl;
	for (int i = 0; i<y; i++)
		q.push(g[i]);
}
int main()
{
	/*cout << "Input addres of file: " << endl;*/
	OpenFile();
	int*A = new int[m];
	int*B = new int[m];
	int ** D = new int*[n];
	for (int i = 0; i<n; i++)
	{
		D[i] = new int[n];
	}
	Read(A, B, D);
	while (1)
	{
		cout << endl;
		cout << "==============================================================" << endl;
		cout << "1. Go through the graph with BFS method." << endl;
		cout << "2. Go through the graph with DFS method." << endl;
		cout << "3. Exit" << endl;
		cout << "--------------------------------------------------------------" << endl;
		int key;
		cout << "Choosen menu item: " << endl;
		cin >> key;
		switch (key)
		{
		case 1: {BFS(D); _getch(); break; }
		case 2: {DFS(D); _getch(); break; }
		case 3: { exit(0); break; }
		default: {cout << "Error" << endl; break; }
		}
	}
	system("pause");
}
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
void Read(int * A, int * B, int**D)
{
	f = fopen(filename, "r");
	for (int i = 0; i<m; i++)
	{
		fscanf(f, "%d%d", &A[i], &B[i]);
	}
	int p = 0;
	int z = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			D[i][j] = 0;
		}
	}
	for (int i = 0; i<m; i++)
	{
		p = A[i];
		z = B[i];
		D[p - 1][z - 1] = D[p - 1][z - 1] + 1;
	}
	fclose(f);
}
void DFS(int**D)
{
	bool l = false, t = false, pr = false;  //булеві змінні
	int h; //змінна
	bool * flag = new bool[n]; //масив відвіданих вершин
	int * dfs = new int[n];  //масив dfs номерів
	int k = 1, v; //змінні
	for (int i = 0; i<n; i++)  //позначити всі вершини не пройденими
		flag[i] = false;
	int nm;
	cout << "Enter the star vertex:  ";
	cin >> nm;
	int mm = nm - 1;
	cout << endl;
	flag[mm] = true; //початкова вершина пройдена
	dfs[mm] = 1;  //позначити початкову вершину в масиві шляху 1
	s.push(mm); //записати в стек початкову вершину
	cout << "Vertex    DFS-number      Stack " << endl;
	cout << "================================================" << endl;
	cout << "   ";
	cout << nm << "          " << dfs[mm] << "           " << nm << endl;
	while (!s.empty())
	{
		t = false;
		v = s.top(); //зчитати змінну
		for (int i = 0; i<n; i++) //перебір матриці суміжості
		{
			if (D[v][i]>0 && flag[i] == false) //якщо вершина суміжна і не пройденна
			{
				t = true;
				h = i;
				break;
			}
		}
		if (t) //найдена суміжна вершина
		{
			l = false;
			k += 1; //збілшити номер
			flag[h] = true; //позначити вершину як відвідану
			dfs[h] = k;  //приписати вершині номер
			s.push(h); //записати в стек
			output(s, l, dfs); //виведення
		}
		else {

			l = true;
			s.pop();  //видалити вершину з стеку
			output(s, l, dfs); //виведення
			if (s.empty())
			{
				for (int i = 0; i<n; i++)
				{
					if (!flag[i])
					{
						l = false;
						s.push(i);
						flag[i] = true;
						break;
					}
				}
			}
		}
	}
	cout << endl;
	cout << "================================================" << endl;
	cout << "Enter any key to contunie..." << endl;
}
void BFS(int**D)
{
	bool l = false, t = false;  //булеві змінні
	int h; //змінна
	bool * flag = new bool[n]; //масив відвіданих вершин
	int * bfs = new int[n];  //масив bfs номерів
	int k = 1, v; //змінні
	for (int i = 0; i<n; i++)  //позначити всі вершини не пройденими
		flag[i] = false;
	int nm;
	cout << "Enter the star vertex:  ";
	cin >> nm;
	int mm = nm - 1;
	cout << endl;
	cout << "Vertex    BFS-number      Queue " << endl;
	cout << "================================================" << endl;
	cout << "   " << nm << "          " << "1" << "           " << nm << endl;
	flag[mm] = true; //початкова вершина пройдена
	q.push(mm); //записати в чергу початкову вершину
	while (!q.empty())
	{
		t = false;
		l = false;
		v = q.front(); //зчитати змінну
		for (int i = 0; i<n; i++) //перебір матриці суміжості
		{
			if (D[v][i]>0 && flag[i] == false) //якщо вершина суміжна і не пройденна
			{
				t = true;
				h = i;
				break;
			}
		}
		if (t) //найдена суміжна вершина
		{
			l = false;
			k += 1; //збілшити номер
			flag[h] = true; //позначити вершину як відвідану
			bfs[h] = k;  //приписати вершині номер
			q.push(h); //записати в стек
			outputs(q, l, bfs); //виведення
		}
		else {
			l = true;
			q.pop();  //видалити вершину з стеку
			outputs(q, l, bfs); //виведення
			if (q.empty())
			{
				for (int i = 0; i<n; i++)
				{
					if (!flag[i])
					{
						l = false;
						q.push(i);
						flag[i] = true;
						break;
					}
				}
			}
		}
	}
	cout << "================================================" << endl;
	cout << "Enter any key to contunie..." << endl;
}
