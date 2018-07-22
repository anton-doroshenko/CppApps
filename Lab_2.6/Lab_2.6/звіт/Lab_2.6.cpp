//Laboratory work
//written by student of the first curse
//of the group IC-52
//Anton Doroshenko
//2016.04.24
//==========================================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;

struct Item
{
	int val;//значення
	Item* next;//покажчик на наступний елемент
};
Item* newptr = NULL;
Item* previous;
Item* head = NULL;//голова
Item* cur;//поточний елемент
Item* last = NULL;//кінець

int N = 0;//кількість елементів
//======= Сворення кыльцевого списку ===========
void create()
{
	cout << "Enter number of components" << endl;
	cin >> N;
	cout << "Enter value" << endl;
	for (int i = 0; i < N; i++)
	{
		newptr = new Item;
		cin >> newptr->val;
		if (head == NULL)
		{
			head = newptr;
			last = head;
			head->next = last;
			last->next = head;
		}
		
		else
		{
			newptr->next = head;
			last->next = newptr;
			last = newptr;
		}
	}
}
//======= Виведення списку ===========
void output()
{
	cur = head;
	if (head == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		cout << "List: ";
		while (true)
		{
			cout << cur->val << " ";
			cur = cur->next;
			if (cur == head)
			{
				break;
			}
		}
		cout << endl;
	}
}
//===== Видалення кожного 3 елемента списку та його виведення ========
void del(Item* ptr)
{
	/*int m = 0;*/
	cur = ptr;
	for (int i = 0; i < 2; i++)
	{
		cur = cur->next;
		if (i == 0)
		{
			previous = cur;
		}
	}
	previous->next = cur->next;
	cout << cur->val << endl;
	cur = NULL;
	/*m++;*/
	if (previous == previous->next)
	{
		cout << previous->val << endl;
		delete previous;
	}
	else/* if (m < N)*/
	{
		del(previous->next);
	}
}

int main()
{
	cout << "laboratory work number 6 made by Anton Doroshenko, IS-52" << endl;
	cout << endl;
	create();
	output();
	if (head != 0)
	{
		cout << "Elements which are deleting: " << endl;
		del(head);
	}
	system("pause");
}