#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>

using namespace std;

int m, n, k;
vector<vector<bool>> v;
vector<vector<bool>> g;
vector<set<pair<int, int>>> vs;


void dfs(set<pair<int,int>>& _s,int _row,int _col)
{
	if (_row < 0
		||
		_col < 0
		||
		_row >= m
		||
		_col >= n
		||
		true == g[_row][_col]
		|| 
		true == v[_row][_col]
		)
	{
		return;
	}
	
	v[_row][_col] = true;
	_s.insert({ _row, _col });

	dfs(_s,_row - 1, _col);
	dfs(_s,_row + 1, _col);
	dfs(_s,_row, _col - 1);
	dfs(_s,_row, _col + 1);
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> k;


	v.resize(m, vector<bool>(n, false));
	g.resize(m, vector<bool>(n, false));


	for (int i = 0; i < k; ++i)
	{
		int l, b, r, t;
		cin >> b>> l>> t>> r;

		for (int i = l; i < r; ++i)
		{
			for (int j = b; j < t; ++j)
			{
				g[i][j] = true;
			}

		}
		
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (false == g[i][j]
				&&
				false == v[i][j])
			{
				set<pair<int, int>> ts;
				dfs(ts, i, j);
				vs.push_back(ts);
			}
		}
	}

	vector<int> vsz;

	for (auto& s : vs)
	{
		vsz.push_back(s.size());
	}

	sort(vsz.begin(), vsz.end());

	cout << vsz.size() << endl;

	for (auto& sz : vsz)
	{
		cout << sz << ' ';
	}

	return 0;
}