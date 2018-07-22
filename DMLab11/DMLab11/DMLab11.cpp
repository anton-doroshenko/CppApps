#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stack>
using namespace std;
stack <int> st;
int pro = 0;
//=====Функція зчитування розмірності графу=======//
void read(FILE *f, int* n, int* m)
{
	fscanf(f, "%d%d", n, m);
}
//========Функція зчитування ребер графу===========//
void scan(FILE* f, int* beg, int* end, int m)
{
	for (int i = 0; i<m; i++)
	{
		fscanf(f, "%d", &beg[i]);  //зчитати першу вершину
		fscanf(f, "%d", &end[i]);  //зчитати другу вершину
	}
}
//=======Функція створення матриці суміжності=========//
void Adjacency(int** Adj, int* beg, int* end, int n, int m)
{
	for (int i = 0; i<n; i++)  //обнулення значення матриці
	for (int j = 0; j<n; j++)
		Adj[i][j] = 0;
	for (int i = 0; i<m; i++)
	{
		Adj[beg[i] - 1][end[i] - 1] += 1; //позначити суміжні вершини
		Adj[end[i] - 1][beg[i] - 1] += 1;  //позначити суміжні вершини
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cout << Adj[i][j] << " ";
		}
		cout << endl;
	}
}
//=======Функція знаходження гамільтонового циклу===========//
int FindGam(int u, int** Adj, int n, bool* flag, bool way)
{
	st.push(u); //записати початкову вершину в стек
	flag[u] = false; //позначити відвіданою вершину
	for (int i = 0; i<n; i++)
	if (Adj[u][i]>0 && flag[i])  //якщо існує суміжна не відвідана вершина
	{
		flag[i] = false; //позначити відвіданою
		pro = FindGam(i, Adj, n, flag, way); //рекурсивний виклик
		if (pro == 1) //якщо існує цикл чи маршрут 
			return 1;
	};
	int k = 0; //лічильник елементів
	for (int i = 0; i<n; i++)
	if (!flag[i])
		k++;
	if (k == n&&Adj[u][0]>0) //якщо існує цикл 
		return 1;
	if ((st.size() == n) && (!way))  //перевірка на гамільтонів маршрут
		return 1;
	st.pop(); //видалення елементу
	flag[u] = true;  //позначити вершину не відвіданою
}
//=======Функція перевірки графа на гамільтонові цикли та шляхи=========//
void Gam(int** Adj, int n)
{
	int p, last;
	bool* flag = new bool[n];
	for (int i = 0; i<n; i++)
		flag[i] = true;
	int u = 0;
	int w = 0;
	bool way = true;
	p = FindGam(u, Adj, n, flag, way); //пошук гамільтонового циклу чи маршруту
	if (p != 1)
	{
		cout << "There is not hamilton cycle!" << endl;
		way = false;
		for (int i = 0; i<n; i++)
		{
			p = FindGam(i, Adj, n, flag, way); //пошук гамільтонового циклу чи маршруту
			if (p == 1)
			{
				cout << "There is hamilton path:" << endl;  //існує маршрут
				do
				{
					cout << st.top() + 1;  //виведення стеку
					st.pop();
					if (st.size() != 0)
						cout << " ->";
				} while (!st.empty());
				break;
			}
		}
	}
	else  //якщо існує цикл
	{
		if (st.size() == n) //якщо всі вершини відвідані
			last = st.top();
		cout << "There is hamilton cycle:" << endl;
		st.push(0); //дописати перший елемент
		do
		{
			cout << st.top() + 1;  //виведення стеку
			st.pop();
			if (st.size() != 0)
				cout << " ->";
		} while (!st.empty());
	}
}
//=========Головна функція=============//
int main()
{
	cout << "Anton Doroshenko IS-52" << endl;
	int n, m; //кількість вершин та ребер
	char filename[100]; //імя файлу
	cout << "Enter the name of the file" << endl;
	cin >> filename;  //введення імені
	FILE *f;   //покажчик на файл
	f = fopen(filename, "r");  //відкриття файлу для читання
	if (f == NULL) cout << "File is not found" << endl;  //якщо не відкрито файл
	else
	{
		read(f, &n, &m);  //зчитати кількість вершин та ребер
		int *beg = new int[m];  //масив перших вершин ребер
		int *end = new int[m];  //масив других вершин ребер
		scan(f, beg, end, m);  //зчитування ребер графу
		fclose(f);
		int **Adj = new int*[n];   //матриця суміжності
		for (int i = 0; i<n; i++)
			Adj[i] = new int[n];
		Adjacency(Adj, beg, end, n, m);  //створення матриці суміжності
		Gam(Adj, n);  //пошук гамільтонових циклів
	}
	cout << endl;
	system("pause");
}
