//Laboratory work
//written by student of the first curse
//of the group IC-52
//Anton Doroshenko
//2015.11.21
//==========================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int n;//кількість елементів
int array[100];//масив, що сортується
bool flag;
//========== генерація масиву =============
void input()
{
	srand((unsigned)time(NULL));//ініціалізація генератора
								//випадкових чисел
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 30; //генерація псевдовипадкових
								//чисел в діапазоні від 0 до 29
	}
}
//========== виведення масиву =============
void output()
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
//=========== сортування масиву вибором ============
void solution()
{
	int mod_two = 0;        //елемент, що ділиться на 2
	int imod_two = 0;       //його індекс
	int mod_two_three = 0;  //елемент, що ділиться на 2 і 3
	int imod_two_three = 0; //його індекс
	int mod_three = 0;      //елемент, що ділиться на 3
	int imod_three = 0;     //його індекс
	int temp = 0;
	//==== числа що діляться на два =======
	for (int i = 0; i < n; i++)
	{
		mod_two = array[i];//пошук елемента, що ділиться на 2
						   //в діапазоні від і-го до останньго
		if (mod_two % 2 == 0 && mod_two % 3 != 0)
		{
			temp = i;
			continue;
		}
		imod_two = i;
		for (int j = i + 1; j < n; j++)//пошук елемента
		{
			flag = false;
			if (array[j] % 2 == 0 && array[j] % 3 != 0)
			{
				imod_two = j;
				mod_two = array[j];
				temp = i;
				flag = true;
			}
			array[imod_two] = array[i];//обмін місцями шуканого елемента
									   //та поточного
			array[i] = mod_two;
			if (flag == true)
			{
				output();         //виведення проміжних результатів
				break;
			}
		}
	}
	//===== числа що діляться на два і на три ========
	if (array[0] % 2 != 0 || array[0] % 3 == 0)
		temp--;
	for (int i = temp + 1; i < n; i++)
	{
		mod_two_three = array[i];
		imod_two_three = i;
		if (mod_two_three % 2 == 0 && mod_two_three % 3 == 0)
		{
			temp = i;
			continue;
		}
		for (int j = i + 1; j < n; j++)
		{
			flag = false;
			if (array[j] % 2 == 0 && array[j] % 3 == 0)
			{
				imod_two_three = j;
				mod_two_three = array[j];
				temp = i;
				flag = true;
			}
			array[imod_two_three] = array[i];
			array[i] = mod_two_three;
			if (flag == true)
			{
				output();
				break;
			}
		}
	}
	//===== числа що діляться на три ========
	for (int i = temp + 1; i < n; i++)
	{
		mod_three = array[i];
		imod_three = i;
		if (mod_three % 3 == 0)
		{
			temp = i;
			continue;
		}
		for (int j = i + 1; j < n; j++)
		{
			flag = false;
			if (array[j] % 3 == 0 && array[j] != 0)
			{
				imod_three = j;
				mod_three = array[j];
				flag = true;
			}
			array[imod_three] = array[i];
			array[i] = mod_three;
			if (flag == true)
			{
				output();
				break;
			}
		}
	}
}

//========== головна функція ===============
int main()
{
	cout << "laboratory work number 7 made by Anton Doroshenko, IS-52" << endl;
	cout << "enter number of the components" << endl;
	input();
	cout << "generated array" << endl;
	output();
	cout << "sort process" << endl;
	solution();
	cout << "sorted array" << endl;
	output();
	system("pause");
}