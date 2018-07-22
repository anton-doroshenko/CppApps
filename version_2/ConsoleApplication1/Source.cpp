#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
int null;
int main()
{
	int n; // the number of temperatures to analyse
	int N;
	cin >> n;
	string temps; // the n temperatures expressed as integers ranging from -273 to 5526
	getline(cin, temps);
	if (temps[0] != '-' && temps[0] != ' ')
	{
		null = (int)temps[0] - '0';
	}
	else if (temps[1] != '-' && temps[1] != ' ')
	{
		if (temps[0] != '-')
		{
			null = -((int)temps[1] - '0');
		}
		else
		{
			null = (int)temps[1] - '0';
		}
	}
	else if (temps[2] != '-' && temps[2] != ' ')
	{
		null = (int)temps[2] - '0';
		if (temps[1] != '-')
		{
			null = -((int)temps[2] - '0');
		}
		else
		{
			null = (int)temps[2] - '0';
		}
	}
	N = n;
	for (int i = 0; i < N + n; i++)
	{
		if ((char)temps[i] == '-')
		{
			N++;
		}
		if ((char)temps[i] != '-' && (char)temps[i] != ' ')
		{
			if (abs((int)temps[i] - '0') < abs(null))
			{
				if (i > 0 && (char)temps[i - 1] == '-')
				{
					null = -((int)temps[i] - '0');
				}
				else
				{
					null = (int)temps[i] - '0';
				}
			}
			if ((((int)temps[i] - '0') == abs(null)) && (((char)temps[i - 1] != '-' && null < 0) || (null >= 0 && (char)temps[i - 1] == '-')))
			{
				null = abs(null);
			}

		}

	}
	//Write an action using cout. DON'T FORGET THE "<< endl"

	//
	cout << null << endl;
}