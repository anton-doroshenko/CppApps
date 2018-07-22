//Laboratory work
//written by student of the first curse
//of the group IC-52
//Anton Doroshenko
//2016.03.11
//==========================================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

FILE *f1;                    //показчик на вхідний файл
FILE *f2;                    //показчик на вихідний файл
char FirmName[10];           //назва фірми
char ProdName[10];           //назва продукту
float DolPrice;              //ціна у доларах
float UkrPrice;              //ціна у гривнях
int Ans = 0;                 //ознака завершення введення даних
int counter = 0;             //лічильник

const float course = 25.55;  //курс долара
//========== Функція введення даних =============
void Input()
{
	do{
		cout << "Enter name of firm" << endl;
		cin >> FirmName;
		cout << "Enter name of product" << endl;
		cin >> ProdName;
		cout << "Enter price of product" << endl;
		cin >> DolPrice;
		fprintf(f1, "%s %s %f\n", FirmName, ProdName, DolPrice);
		cout << "Do you want to continue entering?(if yes enter '1')" << endl;
		counter++;
		cin >> Ans;
	} while (Ans == 1);
	
}
//========== Функція запису в кінець рядка ціни в гривнях
void AddPrice()
{
	f1 = fopen("f.txt", "r");
	f2 = fopen("new.txt", "w");
	for (int i = 0; i < counter; i++)
	{
		fscanf(f1, "%s %s %f", &FirmName, &ProdName, &DolPrice);
		UkrPrice = DolPrice * course;
		fprintf(f2, "%s %s %f %f\n", FirmName, ProdName, DolPrice, UkrPrice);
	}
	fclose(f1);
	fclose(f2);
}
//========== Головна програма ================
int main()
{
	cout << "laboratory work number 1 made by Anton Doroshenko, IS-52" << endl;
	f1 = fopen("f.txt", "w");
	if (f1 == NULL)
	{
		puts("File not open");
	}
	else
	{
		puts("OK");
		Input();
		fclose(f1);
		AddPrice();
		cout << "Operations are done!" << endl;
	}
	system("pause");
}
