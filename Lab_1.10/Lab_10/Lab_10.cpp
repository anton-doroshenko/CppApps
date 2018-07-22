//Laboratory work
//written by student of the first curse
//of the group IC-52
//Anton Doroshenko
//2015.12.11
//==========================================================================
#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;
//оголошення структури
struct firma
{
	char name[15];       //назва фірми
	char ProductName[15];//назва продукту
	float price;         //ціна продукту
	int termin;          //термін постачання продукту
};
//створення масиву структур
firma array[15];
int n = 0;      //кількість фірм у масиві
//======= Функція введення даних про фірми =======
void input()
{
	cout << "How many firms do you want to add in database?" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Please enter\nName of firma:" << endl;
		cin >> array[i].name;
		cout << "Name of product that is sailed:" << endl;
		cin >> array[i].ProductName;
		cout << "Product price:" << endl;
		cin >> array[i].price;
		cout << "How many days client must wait:" << endl;
		cin >> array[i].termin;
	}
	system("pause");
}
//====== Функція виведення даних про фірми =======
void output()
{
	cout << setw(10) << "Name" << setw(15) << "Product name" << setw(10) << "Price" << setw(10) << "Termin" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(10) << array[i].name << setw(15) << array[i].ProductName << setw(10) << array[i].price << setw(10) << array[i].termin << endl;
	}
	system("pause");
}
//====== Функція знаходження фірм, що постачають товар у дводенний срок =======
void SearchTwoDaysFirm()
{
	cout << "Firms that bring product for 2 days" << endl;
	for (int i = 0; i < n; i++)
	{
		if (array[i].termin == 2)
		{
			cout << array[i].name << endl;
		}
	}
	system("pause");
}
//====== Функція визначення назви товару за ціною, що не перевищує заданого значення ========
void SearchProductName()
{
	float MaxPrice = 0;                //ціна значення якої задається
	cout << "Enter max price" << endl;
	cin >> MaxPrice;
	cout << "Products witch price is less than max price" << endl;
	for (int i = 0; i < n; i++)
	{
		if (array[i].price <= MaxPrice)
		{
			cout << array[i].ProductName << endl;
		}
	}
	system("pause");
}
//====== Функція впорядкування масиву за термінами постачання товару =======
void SortArray()
{
	firma temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (array[j].termin < array[i].termin)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	cout << "Sort process is completed!" << endl;
	system("pause");
}
//====== Головна функція ======
int main()
{
	cout << "laboratory work number 9 made by Anton Doroshenko, IS-52" << endl;
	while (true)
	{
		system("cls");
		int key = 0;            //номер пункту меню
		cout << "Menu" << endl;
		cout << "1.Input data" << endl;
		cout << "2.Output data" << endl;
		cout << "3.Two days" << endl;
		cout << "4.Products witch price is less than ..." << endl;
		cout << "5.Sort arrays by termins" << endl;
		cout << "6.Exit" << endl;
		cout << "Enter your choose: ";
		cin >> key;                  //вибір потрібного пункту меню
		switch (key)
		{
		case 1: input();             //ведення даних
			break;
		case 2: output();            //виведення даних
			break;
		case 3: SearchTwoDaysFirm(); //знаходження фірм, що постачають товар у дводенний срок
			break;
		case 4:  SearchProductName();//визначення назви товару за ціною, що не перевищує заданого значення
			break;
		case 5: SortArray();         //впорядкування масиву за термінами постачання товару
			break;
		case 6: exit(0);             //вихід з програми
			break;
		default: cout << "Please, try again..." << endl;
			system("pause");
			break;
		}
	}
}