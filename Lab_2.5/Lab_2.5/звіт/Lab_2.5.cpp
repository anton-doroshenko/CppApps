//Laboratory work
//written by student of the first curse
//of the group IC-52
//Anton Doroshenko
//2016.04.10
//==========================================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;
//черга
struct Item
{
	char val;//значення
	Item* next;//покажчик на наступний елемент
};
Item* head = NULL;//голова 1 черги
Item* cur;//поточний елемент
Item* last = NULL;//кінець 1 черги
Item* head2 = NULL;//голова 2 черги
Item* last2 = NULL;//кінець 2 черги

FILE* f;

char sym;
char* ptrch = &sym;
int N = 0;//кількість елементів черги
//====== Функція додавання елементу до 1 черги ========
void add()
{
	cur = new Item;
	cur->val = sym;
	cur->next = NULL;
	if (last == NULL)
	{
		head = cur;
	}
	else
	{
		last->next = cur;
	}
	last = cur;
}
//====== Функція додавання елементу до 2 черги ========
void add2()
{
	cur = new Item;
	cur->val = sym;
	cur->next = NULL;
	if (last2 == NULL)
	{
		head2 = cur;
	}
	else
	{
		last2->next = cur;
	}
	last2 = cur;
}
//====== Функція видалення елементу з 1 черги ========
void pop(char* value)
{
	cur = head;
	*value = head->val;
	head = cur->next;
	if (head == NULL)
	{
		last = NULL;
	}
	delete cur;
}
//====== Функція видалення елементу з 2 черги ========
void pop2(char* value)
{
	cur = head2;
	*value = head2->val;
	head2 = cur->next;
	if (head2 == NULL)
	{
		last2 = NULL;
	}
	delete cur;
}
//====== Функція копіювання черги та виведення результатів ========
void copyAndRes()
{
	cout << "First queue: ";
	while (head != NULL)
	{
		pop(ptrch);
		add2();
		cout << sym << " ";
		N++;
	}
	cout << endl;
	cout << "Second queue: ";
	while (head2 != NULL)
	{
		pop2(ptrch);
		cout << sym << " ";
	}
	cout << endl;
	cout << "The number of elements is " << N << endl;
}
//=========== Головна функція ==============
int main()
{
	cout << "laboratory work number 5 made by Anton Doroshenko, IS-52" << endl;
	cout << endl;
	f = fopen("f.txt", "r");
	while ((sym = fgetc(f)) != EOF)
	{	
		add();
	}
	fclose(f);
	if (head == NULL)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		cout << "Queue isn`t empty" << endl;
		copyAndRes();
	}
	system("pause");
}