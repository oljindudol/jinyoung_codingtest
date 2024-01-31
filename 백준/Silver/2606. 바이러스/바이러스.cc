#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_set>

using namespace std;

int cntcom;
int cntpair;

vector<bool> v;
vector<vector<bool>> g;

int ret;

void dfs(int _f)
{
	if (true == v[_f])
	{
		return;
	}
	v[_f] = true;
	++ret;

	for (int i = 0; i < cntcom; ++i)
	{
		if (true == g[_f][i])
		{
			dfs(i);
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> cntcom >> cntpair;

	g.resize(cntcom, vector<bool>(cntcom, false));
	v.resize(cntcom, false);

	if (1 == cntcom)
	{
		cout << 0;
		return ret;
	}

	for (int i = 0; i < cntpair; ++i)
	{
		int f, t;
		cin >> f >> t;
		g[f - 1][t - 1] = true;
		g[t - 1][f - 1] = true;
	}

	dfs(0);
	--ret;
	cout << ret;
	return 0;
}