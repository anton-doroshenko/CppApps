#include <iostream>

using namespace std;

int i = 0;
int ic, isum, iave;
float fc, fsum, fave;
char chc, chsum, chave;
long lc, lsum, lave;
double dc, dsum, dave;

template <class T>
T Average( T c, T sum, T ave)
{		
	while (cin >> c && c != 0 )
	{
		if (c == 101)
			break;
		sum += c;
		i++;
	}
	ave = sum / i;
	i = 0;
	return ave;
}
int main()
{
	cout << "Calculating arithmetic average using tamplate" << endl;
	cout << "Made by Anton Doroshenko" << endl;
	//Обчислення середнього арифметичного чисел типу int
	cout << "Enter integer numbers (the end of row is '0')" << endl;
	iave = Average(ic, isum, iave);
	cout << "arithmetic average = " << iave << endl;
	//Обчислення середнього арифметичного символів
	cout << "Enter char symbols (the end of row is 'e')" << endl;
	chave = Average(chc, chsum, chave);
	cout << "arithmetic average = " << chave << endl;
	//Обчислення середнього арифметичного чисел типу long
	cout << "Enter long integer numbers (the end of row is '0')" << endl;
	lave = Average(lc, lsum, lave);
	cout << "arithmetic average = " << lave << endl;
	//Обчислення середнього арифметичного чисел типу float
	cout << "Enter float numbers (the end of row is '0')" << endl;
	fave = Average(fc, fsum, fave);
	cout << "arithmetic average = " << fave << endl;
	//Обчислення середнього арифметичного чисел типу double
	cout << "Enter double numbers (the end of row is '0')" << endl;
	dave = Average(dc, dsum, dave);
	cout << "arithmetic average = " << dave << endl;
	system("pause");

	return 0;
}