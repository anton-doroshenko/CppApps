#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

char str[15];      //рядок, що вводиться
int n = 0;         //кількість дужок, що відкриваються
int m = 0;         //кількість дужок, що закриваються
//====== Функція обробки рядка =======
void processing()
{
	char OpenBr = '(';      //дужка, що відкривається
	char CloseBr = ')';     //дужка, що закривається
	int clind = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == OpenBr)
		{
			n++;
			for (int j = clind; j < strlen(str); j++)
			{
				if (str[j] == CloseBr)
				{
					clind = j;
					n--;
					break;
				}
			}
		}
		else if (str[i] == CloseBr)
		{
			m++;
		}
	}
}
//===== Функція виведення результатів ======
void OutputResult()
{
	if (n == m)
	{
		cout << "There are balans of brackets in the string\nTrue" << endl;
	}
	else
	{
		cout << "There are not balans of brackets in the string\nFalse" << endl;
	}
}

int main()
{
	cout << "Please enter your string:" << endl;
	gets(str);
	processing();
	OutputResult();
	system("pause");
}