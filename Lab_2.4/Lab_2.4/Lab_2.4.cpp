//Laboratory work
//written by student of the first curse
//of the group IC-52
//Anton Doroshenko
//2016.04.03
//==========================================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;
//Стек
struct Item
{
	char val;
	Item* next;
};

char str[100];//допоміжний рядок
char sym;//змінна для зберігання значень символів
char* ptrs = &sym;
char oper[] = "abcdefghijklmnopqrstuvwxyz";//операнди
char operatio[] = "+-*/";//операції
int operand = 0;
int operations = 0;

Item* head = NULL;
Item* cur;
FILE* f;
//додавання елемента до стеку
void push(char value)
{
	cur = new(Item);
	cur->val = value;
	cur->next = head;
	head = cur;
}
//видалення та зберігання елемента стеку
void pop(char* value)
{
	cur = head;
	*value = head->val;
	head = cur->next;
	delete cur;
}
//Визначення кількості операндів і операцій та виведення елементів стеку
void outElemOfStack()
{
	while (head != NULL)
	{
		pop(ptrs);
		cout << sym << " ";
		if (strchr(oper, sym) != 0)
		{
			operand++;
		}
		else if (strchr(operatio, sym) != 0)
		{
			operations++;
		}
	}
}

int main()
{
	cout << "laboratory work number 3 made by Anton Doroshenko, IS-52" << endl;
	f = fopen("fff.txt", "r");
	int k = 1;
	while (!feof(f))
	{
		fscanf(f, "%s", str);
		for (int i = 0; i < strlen(str); i++)
		{
			push(str[i]);
		}
		cout << "Elements of stack:" << endl;
		outElemOfStack();
		cout << endl;
		cout << k << " expression has: " << operand << " operands and " << operations << " operations" << endl;
		k++;
		operand = 0;
		operations = 0;
	}
	system("pause");
	fclose(f);
}