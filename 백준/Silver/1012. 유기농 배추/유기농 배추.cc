#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_set>
#include<queue>
#include<stdio.h>

using namespace std;

int cnt;

vector<vector<int>> g;
vector<vector<bool>> v;

vector<int> vrow = { 1, -1,0,0 };
vector<int> vcol = { 0,0,-1,1 };
int m, n;

vector<int> out;

bool checkrow(int _row)
{
	if (0 > _row || m <= _row)
		return false;

	return true;
}

bool checkcol(int _col)
{
	if (0 > _col || n <= _col)
		return false;

	return true;
}

void dfs(int _row, int _col)
{
	if (!checkrow(_row) ||
		!checkcol(_col) ||
		0==g[_row][_col] ||
		true == v[_row][_col]
		)
	{
		return;
	}
	
	v[_row][_col] = true;

	for (int i = 0; i < 4; ++i)
	{
		dfs(_row + vrow[i], _col + vcol[i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;


	for (int r = 0; r < t; ++r)
	{
		int ret = 0;

		int k;

		cin >> m >> n >> k;

		g.resize(0);
		g.resize(m, vector<int>(n, 0));
		v.resize(0);
		v.resize(m, vector<bool>(n, false));


		//배추심기
		for (int i = 0; i < k; ++i)
		{
			int inrow, incol;
			cin >> inrow >> incol;
			g[inrow][incol] = 1;
		}

		//벌레
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (1 == g[i][j] && false == v[i][j])
				{
					++ret;
					dfs(i, j);
				}
			}
		}
		out.push_back(ret);
	}

	for (auto& o : out)
	{
		cout << o<<endl;
	}

	return 0;
}