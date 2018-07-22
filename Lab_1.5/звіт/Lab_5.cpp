//Laboratory work
//written by student of the first curse
//of the group IC-52
//Anton Doroshenko
//2015.11.08
//==========================================================================

#include <iostream>

using namespace std;

int depth = 0;               //Поточна глибина рекурсії
int dout = 0;                //Найбільша глибина рекурсії
float sum;                   //Сума
int p, q;                    //Початкове і кінцеве значення параметра суми

float F(int n)               //Оголошення функції
{
	depth += 1;              //Збільшити поточну глибину на 1
	if (n % 10 > 0)
		return (float)(n % 10);
	else if (n == 0) 
		return 0;
	else
		return F(n / 10);    //Рекурсивний виклик функції
}
float S(int p, int q)        //Функція обчислення суми
{
	for (int i = p; i <= q; i++)
	{
		sum += F(i);
		if (dout < depth)    //Якщо поточна глибина рекурсії більше найбільшої
			dout = depth;    //присвоїти значення поточної глибини найбільшій
		depth = 0;           //Обнулити поточну глибину рекурсії
	}
	return sum;
}
int main()
{
	int cont;
	cout << "laboratory work number 5 made by Anton Doroshenko, IS-52" << endl;
	do{
		cout << "Please, enter p, q" << endl;
		cin >> p >> q;
		S(p, q);             //Виклик функції для обчислення суми
		cout << "sum = " << sum << endl;
		cout << "depth = " << dout << endl;
		cout << "If you want to start again enter 1" << endl;
		cin >> cont;
	} while (cont == 1);
}