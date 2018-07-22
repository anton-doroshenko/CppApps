/* Лабораторна робота номер 1
виконав студент першого курсу групи ІС-52
Дорошенко Антон */
#define _CRT_SECURE_NO_WARNINGS 
#define _USE_MATH_DEFINES //включення макровизначень
#include <iostream>//бібліотека потоків вводу-виводу
#include <math.h>//бібліотека математичних функцій
#include <stdio.h>//бібліотека стандартного введення-виведення
#include <conio.h>//бібліотека консольного введення-виведення

using namespace std;

int main()//основна функція
{
	int symbol;
	char str[15];
	/*функції putchar(), getchar()*/
	cout << " usage of functions putchar(), getchar()\n" << endl;//виведення повідомлення
	puts("Enter your symbol");//виведення повідомлення
	symbol = getchar();//введення рядка
	putchar(symbol);//виведення символу
	fflush(stdin);//очищення буфера
	/*функції gets(), puts()*/
	cout << "\n\n usage of functions gets(), puts()\n" << endl;//виведення повідомлення
	puts("Enter string");//виведення повідомлення
	gets(str);//введення рядка
	puts(str);//виведення рядка
	/*функції scanf(), printf()*/
	cout << "\n usage of functions scanf(), printf()\n" << endl;//виведення повідомлення
	puts("enter symbol and string");//виведення повідомлення
	scanf("%c%s", &symbol, str);//введення данних
	printf("%c\n%s\n", symbol, str);//виведення символу і рядка
	fflush(stdin);//очищення буфера
	/*функції sscanf(), sprintf()*/
	char str2[30];
	cout << "\nusage of functions sscanf(), sprintf()\n" << endl;//виведення повідомлення
	sscanf(str, "%s", &str);//введення данних із рядка до буфера
	puts("Results are not displayed when we use function sscanf()");//виведення повідомлення
	fflush(stdin);//очищення буфера
	sprintf(str2,"symbol=%c (format char)", symbol);//запис значення змінної типу char до рядка
	puts(str2);//виведення рядка
	sprintf(str2, "symbol=%d (format int)", symbol);//запис значення змінної типу int до рядка
	puts(str2);//виведення рядка
	/*Визначення значення виразу за допомогою матетатичних функцій*/
	cout << "\n calculate expression\n" << endl;
	float a, b, c, d, x;
	puts("x = (a^2 - b^2)*(c - d) /sqrt(M_E*(a^2 - b^2))");
	puts("Enter a, b, c, d");//виведення повідомлення
	scanf("%f%f%f%f", &a, &b, &c, &d);//введення данних
	if (a <= b)//умова існування виразу
	{
	puts("Error: expression has no solutions on the set of real numbers");//виведення повідомлення
	}
	else
	{
		x = ((a*a - b*b)*(c - d)) / (sqrt(M_E*(a*a - b*b)));//вираз
		printf("x = %f\n", x);//виведення повідомлення
	}
	system("pause");
}