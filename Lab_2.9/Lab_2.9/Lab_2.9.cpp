//Laboratory work
//written by student of the first curse
//of the group IC-52
//Anton Doroshenko
//2016.05.04
//==========================================================================
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <cstring>

using namespace std;

const int oo = 1 << 30;
const int neftemu = -(1000000100);
int a, h, n, m;
vector <int> f[2505], g[2505], c[2505], rev[2505], ok[2505];
bool used[2505];
//пошук в глиб
int dfs(int v, int C, int d) {
	used[v] = true;
	if (v == n - 1)
		return C;
	for (int i = 0; i < g[v].size(); i++)
	if (!used[g[v][i]] && c[v][i] - f[v][i] >= d) {
		int k = dfs(g[v][i], min(C, c[v][i] - f[v][i]), d);
		if (k) {
			f[v][i] += k, f[g[v][i]][rev[v][i]] -= k;
			return k;
		}
	}
	return 0;
}

vector <pair <int, int> > e;
int t[2505][2505];


int ok1(char el) {
	if (el == 'H')
		return 1;
	if (el == 'O')
		return 2;
	if (el == 'N')
		return 3;
	if (el == 'C')
		return 4;
	return 0;
}
//Дооавання ребра
void add_edge(int u, int v, int w) {

	e.push_back(make_pair(u, v));

	f[u].push_back(0);
	c[u].push_back(w);
	g[u].push_back(v);
	ok[u].push_back(true);
	rev[u].push_back(g[v].size());

	f[v].push_back(0);
	c[v].push_back(0);
	ok[v].push_back(false);
	g[v].push_back(u);
	rev[v].push_back(g[u].size() - 1);

	t[u][v] = e.size() - 1;

}

int num[51][51];
//Головна функція
int main() {
	cout << "laboratory work number 8 made by Anton Doroshenko, IS-52" << endl;
	cout << endl;
	cout << "Enter size of sheet" << endl;
	int h, w;
	cin >> h >> w;
	cout << "Enter elements" << endl;
	n = 1;
	string st[8888];
	int cnt = 1;
	bool t = false;
	for (int i = 0; i < h; i++) {
		cin >> st[i];
		for (int j = 0; j < w; j++) {
			num[i][j] = i * w + j + 1;
			if (st[i][j] != '.')
				t = true;
		}
	}


	if (!t) {
		puts("Invalid");
		return 0;
	}

	int potok = 0;
	n = h*w + 2;
	for (int i = 0; i < h; i++)
	for (int j = 0; j < w; j++) {
		if (((i & 1) && (j & 1)) || (!(i & 1) && !(j & 1))) {
			add_edge(0, num[i][j], ok1(st[i][j]));
			potok += ok1(st[i][j]);
			if (i + 1 < h)
				add_edge(num[i][j], num[i + 1][j], 1);
			if (j + 1 < w)
				add_edge(num[i][j], num[i][j + 1], 1);
			if (i - 1 >= 0)
				add_edge(num[i][j], num[i - 1][j], 1);
			if (j - 1 >= 0)
				add_edge(num[i][j], num[i][j - 1], 1);
		}
		else
			add_edge(num[i][j], n - 1, ok1(st[i][j]));
	}

	long long s = 0ll;
	for (int i = (1 << 30); i >= 1; i >>= 1) {
		while (1) {
			memset(used, false, sizeof used);
			int k = dfs(0, oo, i);
			if (!k)
				break;
			s += k;
		}
	}

	if (s == potok)
		cout << "Valid";
	else
		cout << "Invalid";
	cout << endl;
	system("pause");
	return 0;
}