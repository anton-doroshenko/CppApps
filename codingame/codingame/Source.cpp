#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
vector<int> bin(7);
string result = " ";
int temp;

int binary(int d, int iter)
{
	if (d == 0)
	{
		return 0;
	}
	else
	{
		bin[iter] = (d - (2 * (d / 2)));
		binary(d / 2, --iter);
	}
}

int main()
{
	string MESSAGE;
	getline(cin, MESSAGE);
	for (int i = 0; i < MESSAGE.size(); i++)
	{
		binary((int)MESSAGE[i], 6);
		for (int j = 0; j < 7; j++)
		{
			if (j == 0 && bin[j] == 0)
			{
				if (i == 0)
				{
					result = "00 0";
				}
				else
				{
					if (bin[j] != temp)
					{
						result += " 00 0";
					}
					else
					{
						result += "0";
					}
				}
			}
			else if (j == 0 && bin[j] == 1)
			{
				if (i == 0)
				{
					result = "0 0";
				}
				else
				{
					if (bin[j] != temp)
					{
						result += " 0 0";
					}
					else
					{
						result += "0";
					}
				}
			}
			else
			{
				if (bin[j] == 0 && bin[j - 1] == 0 || bin[j] == 1 && bin[j - 1] == 1)
				{
					result += "0";
				}
				else if ((bin[j] == 0) && (bin[j - 1] == 1))
				{
					result += " 00 0";
				}
				else if ((bin[j] == 1) && (bin[j - 1] == 0))
				{
					result += " 0 0";
				}

			}
		}
		temp = bin[6];
	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	cout << result << endl;
}