//Laboratory work
//written by student of the first curse
//of the group IC-52
//Anton Doroshenko
//2016.03.13
//==========================================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;

struct Product
{
	char name[100];//ім'я товару
	int term = 0;//термін поставки
	float Price = 0;//ціна товару
};

struct Firm
{
	char Name[100];//ім'я фірми
	int Quantity = 0;//кількість товарів
	Product prod[100];
};
//створення масиву структур
Firm Arr[15];
FILE* f, *ftmp;
int counter = 0;//номер фірми

void input()
{
	f = fopen("ddd.dat", "wb");
	int Ans = 0;                 //ознака завершення введення даних
	do{
		cout << "Please enter\nName of firm:" << endl;
		cin >> Arr[counter].Name;
		cout << "How many products are produced by " << Arr[counter].Name << "?" << endl;
		cin >> Arr[counter].Quantity;
		for (int i = 0; i < Arr[counter].Quantity; i++)
		{
			cout << "Name of product that is sailed:" << endl;
			cin >> Arr[counter].prod[i].name;
			cout << "Product price:" << endl;
			cin >> Arr[counter].prod[i].Price;
			cout << "How many days client must wait:" << endl;
			cin >> Arr[counter].prod[i].term;
		}
		fwrite(&Arr[counter], sizeof(Firm), 1, f);
		counter++;
		cout << "Do you want to continue entering?(if yes enter '1')" << endl;
		cin >> Ans;
	} while (Ans == 1);
	fclose(f);
	system("pause");
}

void Output()
{
	int i = 1;//номер фірми
	Firm arr;
	f = fopen("ddd.dat", "rb");
	cout << setw(10) << "Name" << setw(15) << "Product name" << setw(10) << "Price" << setw(10) << "Termin" << endl;
	while (!feof(f))
	{
		fread(&arr, sizeof(Firm), 1, f);
		for (int j = 0; j < arr.Quantity; j++)
		{
			if (feof(f))
			{
				break;
			}
			cout << i << setw(9) << arr.Name << setw(15) << arr.prod[j].name << setw(10) << arr.prod[j].Price << setw(10) << arr.prod[j].term << endl;
		}
		i++;
	}
	fclose(f);
	system("pause");
}

void AddNewInform()
{
	f = fopen("ddd.dat", "a+b");
	int Ans = 0;                 //ознака завершення введення даних
	do{
		cout << "Please enter\nName of firm:" << endl;
		cin >> Arr[counter].Name;
		cout << "How many products are produced by " << Arr[counter].Name << "?" << endl;
		cin >> Arr[counter].Quantity;
		for (int i = 0; i < Arr[counter].Quantity; i++)
		{
			cout << "Name of product that is sailed:" << endl;
			cin >> Arr[counter].prod[i].name;
			cout << "Product price:" << endl;
			cin >> Arr[counter].prod[i].Price;
			cout << "How many days client must wait:" << endl;
			cin >> Arr[counter].prod[i].term;
		}
		fseek(f, sizeof(Firm), SEEK_CUR);
		fwrite(&Arr[counter], sizeof(Firm), 1, f);
		counter++;
		cout << "Do you want to continue entering?(if yes enter '1')" << endl;
		cin >> Ans;
	} while (Ans == 1);
	fclose(f);
	system("pause");
}

void Change()
{
	Firm arr;
	int number = 0;//номер фірми
	f = fopen("ddd.dat", "r+b");
	cout << "Which firm you want to change?" << endl;
	cin >> number;
	fseek(f, (number - 1) * sizeof(Firm), SEEK_SET);
	cout << "Please enter\nName of firm:" << endl;
	cin >> arr.Name;
	cout << "How many products are produced by " << arr.Name << "?" << endl;
	cin >> arr.Quantity;
	for (int i = 0; i < arr.Quantity; i++)
	{
		cout << "Name of product that is sailed:" << endl;
		cin >> arr.prod[i].name;
		cout << "Product price:" << endl;
		cin >> arr.prod[i].Price;
		cout << "How many days client must wait:" << endl;
		cin >> arr.prod[i].term;
	}
	fwrite(&arr, sizeof(Firm), 1, f);
	fclose(f);
	system("pause");
}

void Delate()
{
	Output();
	Firm arr;
	int number = 0;//номер фірми
	int Locate = 0;//адреса розміщення фірми у файлі
	f = fopen("ddd.dat", "rb");
	ftmp = fopen("buf.dat", "wb");
	cout << "Which firm you want to delate?" << endl;
	cin >> number;
	Locate = (number - 1) * sizeof(Firm);
	while (!feof(f))
	{
		if (feof(f))
		{
			break;
		}
		if (ftell(f) == Locate)
		{
			
			fread(&arr, sizeof(Firm), 1, f);
			continue;
		}
		else {
			size_t ret = fread(&arr, sizeof(Firm), 1, f);
			if (ret != 0) {
			fwrite(&arr, sizeof(Firm), 1, ftmp);
			}
		}
	}
	fclose(f);
	fclose(ftmp);
	f = fopen("ddd.dat", "wb");
	ftmp = fopen("buf.dat", "r+b");
	while (!feof(ftmp))
	{
		if (feof(ftmp))
		{
			break;
		}
		size_t ret = fread(&arr, sizeof(Firm), 1, ftmp);
		if (ret != 0)
		{
			fwrite(&arr, sizeof(Firm), 1, f);
		}
	}
	fclose(f);
	fclose(ftmp);
	remove("buf.dat");
	Output();
}

void SearchTwoDaysFirm()
{
	Firm arr;
	char Name[100];
	cout << "Enter name of the product" << endl;
	cin >> Name;
	f = fopen("ddd.dat", "r+b");
	fseek(f, 0L, SEEK_END);
	fpos_t pos;
	fgetpos(f, &pos);
	int index = pos / sizeof(Firm);
	for (int i = 0; i < index; i++)
	{
		fseek(f, i * sizeof(Firm), SEEK_SET);
		fread(&arr, sizeof(Firm), 1, f);
		for (int j = 0; j < arr.Quantity; j++)
		{
			if ((strcmp(arr.prod[j].name, Name) == 0) && arr.prod[j].term == 2)
			{
				cout << arr.Name << " bring " << arr.prod[j].name << " for 2 days" << endl;
			}
		}
	}
	fclose(f);
	system("pause");
}

void SearchProductName()
{
	Firm arr;
	f = fopen("ddd.dat", "r+b");
	fseek(f, 0L, SEEK_END);
	fpos_t pos;
	fgetpos(f, &pos);
	int index = pos / sizeof(Firm);
	char Name[100];
	float MaxPrice = 0;                //ціна значення якої задається
	cout << "Enter max price" << endl;
	cin >> MaxPrice;
	cout << "Enter name of the firm" << endl;
	cin >> Name;
	cout << "Products of firm " << Name << " which price is less than "<< MaxPrice << endl;
	for (int i = 0; i < index; i++)
	{
		fseek(f, i * sizeof(Firm), SEEK_SET);
		fread(&arr, sizeof(Firm), 1, f);
		if (strcmp(Name, arr.Name) == 0)
		{
			for (int j = 0; j < arr.Quantity; j++)
			{
				if (arr.prod[j].Price <= MaxPrice)
				{
					cout << arr.prod[j].name << endl;
				}
			}
		}
	}
	fclose(f);
	system("pause");
}

void SortArray()
{
	float SumTerm = 0;
	float MidTerm[100];
	float temp = 0;
	Firm array1, array2, Temp;
	f = fopen("ddd.dat", "r+b");
	fseek(f, 0L, SEEK_END);
	fpos_t pos;
	fgetpos(f, &pos);
	int index = pos / sizeof(Firm);
	for (int i = 0; i < index; i++)
	{
		fseek(f, i * sizeof(Firm), SEEK_SET);
		fread(&array1, sizeof(Firm), 1, f);
		for (int j = 0; j < array1.Quantity; j++)
		{
			SumTerm += array1.prod[j].term;
		}
		MidTerm[i] = SumTerm / array1.Quantity;
		SumTerm = 0;
	}
	for (int i = 0; i < index - 1; i++)
	{
		
		for (int j = i + 1; j < index; j++)
		{
				
			if (MidTerm[j] < MidTerm[i])
			{
				fseek(f, i * sizeof(Firm), SEEK_SET);
				fread(&array1, sizeof(Firm), 1, f);
				fseek(f, j * sizeof(Firm), SEEK_SET);
				fread(&array2, sizeof(Firm), 1, f);
				fseek(f, i * sizeof(Firm), SEEK_SET);
				fwrite(&array2, sizeof(Firm), 1, f);
				fseek(f, j * sizeof(Firm), SEEK_SET);
				fwrite(&array1, sizeof(Firm), 1, f);
				temp = MidTerm[i];
				MidTerm[i] = MidTerm[j];
				MidTerm[j] = temp;
			}
		}
	}
	fclose(f);
	cout << "Sort process is completed!" << endl;
	system("pause");
}

int main()
{
	while (true)
	{
		system("cls");
		int key = 0;            //номер пункту меню
		cout << "laboratory work number 9 made by Anton Doroshenko, IS-52" << endl;
		cout << "Menu" << endl;
		cout << "1.Input data" << endl;
		cout << "2.Output data" << endl;
		cout << "3.Two days" << endl;
		cout << "4.Products witch price is less than ..." << endl;
		cout << "5.Sort arrays by termins" << endl;
		cout << "6.Add a new information to file" << endl;
		cout << "7.Change an information" << endl;
		cout << "8.Delate data" << endl;
		cout << "9.Exit" << endl;
		cout << "Enter your choose: ";
		cin >> key;                  //вибір потрібного пункту меню
		switch (key)
		{
		case 1: input();             //ведення даних
			break;
		case 2: Output();            //виведення даних
			break;
		case 3: SearchTwoDaysFirm(); //знаходження фірм, що постачають товар у дводенний срок
			break;
		case 4:  SearchProductName();//визначення назви товару за ціною, що не перевищує заданого значення
			break;
		case 5: SortArray();         //впорядкування масиву за термінами постачання товару
			break;
		case 6: AddNewInform();         //доповнення файлу
			break;
		case 7: Change();         //заміна даних
			break;
		case 8: Delate();         //видалення даних
			break;
		case 9: exit(0);             //вихід з програми
			break;
		default:{ cout << "Please, try again..." << endl;
			system("pause");
			break; }
		}
	}
}