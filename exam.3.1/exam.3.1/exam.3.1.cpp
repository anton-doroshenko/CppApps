#include <iostream> 

using namespace std;

const int dxh[] = { -2, -2, 2, 2, -1, -1, 1, 1 };
const int dyh[] = { -1, 1, -1, 1, -2, 2, -2, 2 };

bool in(int i, int j, int n, int m)
{
	return i >= 1 && i <= n && j >= 1 && j <= m;
}

int ans = 0;
int n, need;

void rec(int i, int j, int k)
{
	if (i < 1 || i > n || j < 1 || j > n)
		return;
	if (k == need)
	{
		if (i == 1 && j == n)
			ans++;
		return;
	}

	for (int dir = 0; dir < 8; dir++)
	{
		int ni = i + dxh[dir];
		int nj = j + dyh[dir];
		rec(ni, nj, k + 1);
	}
}

int main()
{
	cin >> n >> need;
	rec(n, 1, 0);
	cout << ans << endl;
	system("pause");
	return 0;
}