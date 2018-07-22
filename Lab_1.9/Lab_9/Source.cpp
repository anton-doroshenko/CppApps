//Laboratory work
//written by student of the first curse
//of the group IC-52
//Anton Doroshenko
//2015.12.06
//==========================================================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

bool flag = false;
char str[15];      //рядок, що вводиться
char str1[15];     //рядок з якого вилучається деякий елемент
char str2[15];     //рядок з якого вилучається інший елемент
char symbol;       //символ, що видаляється
char* p;           //покажчик на шуканий символ
int ind = 0;       //індекс символу в рядку
//====== Функція пошуку індекса елемента, що видаляється ======
void SearchSymIndex(char* string)
{
	do
	{
		cout << "Enter symbol, which you want to delete" << endl;
		cin >> symbol;
		p = strchr(string, symbol);
		ind = p - string;
		if (p == 0)
		{
			cout << "The symbol is not found\nPlease try again" << endl;
		}
	} while (p == 0);
}
//====== Функція видалення заданого символу ======
void DeleteSymbol(int index, char* string)
{
	int n = strlen(string) - 1;            //індекс останньго елемента
	for (int i = index; i < n; i++)       
	{
		string[i] = string[i + 1];
	}
	string[n] = '\0';
}
//====== Функція пошуку індексу перших різних елементів ======
void SearchDifSymInd(char* string1, char* string2)
{
	ind = 0;
	int n = strlen(string1) - 1; //індекс останнього елемента
	for (int i = 0; i < n; i++)
	{
		if (string1[i] != string2[i])
		{
			flag = true;
			break;
		}
		ind++;
	}
}
//====== Функція зсуву частини рядка вправо ======
void RightReplace(int index, char* string)
{
	int n = strlen(string) - 1;
	for (int i = n; i >= index; i--)
	{
		string[i + 1] = string[i];
	}
}
//====== Функція відновлення рядка ======
void Recovery(int index)
{
	char temp;
	int cmp = 0;
	if (index == strlen(str1) - 1)//якщо неоднакові
	{                             //елементи останні
		//видалені елементи суміжні тому буде два варіанти відновлення
		RightReplace(index, str2);
		str2[index] = str1[index];//вставку елементу з першого рядка в другий
		cout << str2 << endl;     //виведення 1 варіанта
		//перестановка двох елементів
		temp = str2[index + 1];
		str2[index + 1] = str2[index];
		str2[index] = temp;
		cout << "or\n" << str2 << endl;//виведення 2 варіанта
	}
	else if (index != strlen(str1) - 1)
	{
		cmp = strcmp(str1 + index + 1, str2 + index + 1);
		if (cmp == 0)
		{
			RightReplace(index, str2);
			str2[index] = str1[index];
			cout << str2 << endl;
			temp = str2[index + 1];
			str2[index + 1] = str2[index];
			str2[index] = temp;
			cout << "or\n" << str2 << endl;//виведення 2 варіанта
		}
		else
		{
			if (str2[index + 1] == str1[index])
			{
				RightReplace(index, str1);
				str1[index] = str2[index];
				cout << str1 << endl;
			}
			else
			{
				RightReplace(index, str2);
				str2[index] = str1[index];
				cout << str2 << endl;
			}
		}
	}
}
//====== Головна функція ======
int main()
{
	cout << "laboratory work number 9 made by Anton Doroshenko, IS-52" << endl;
	cout << "Enter string" << endl;
	gets(str);                         //введення рядка
	strcpy(str1, str);                 //копіювання рядка
	strcpy(str2, str);                 //копіювання рядка
	SearchSymIndex(str1);
	DeleteSymbol(ind, str1);           
	SearchSymIndex(str2);
	DeleteSymbol(ind, str2);
	cout << "Strings after deleting:" << endl;
	cout << str1 << endl;
	cout << str2 << endl;
	SearchDifSymInd(str1, str2);
	if (flag == true)
	{
		cout << "Recovering string:" << endl;
		Recovery(ind);
	}
	else
	{
		cout << "The same elements are deleting, string can't be recovered" << endl;
	}
	system("pause");
}