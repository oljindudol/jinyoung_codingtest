#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>

using namespace std;

int m, n;
vector<vector<char>> g;
int ret;


void dfs(int _row,int _col)
{
	if (_row < 0
		||
		_col < 0
		||
		_row >= m
		||
		_col >= n
		||
		'X' == g[_row][_col]
		)
	{
		return;
	}
	if ('P' == g[_row][_col])
	{
		++ret;
	}

	g[_row][_col] = 'X';

	dfs(_row - 1, _col);
	dfs(_row + 1, _col);
	dfs(_row, _col - 1);
	dfs(_row, _col + 1);
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ret = 0;

	pair<int, int> me;

	cin >> m >> n ;


	g.resize(m, vector<char>(n, 'O'));


	for (int i = 0; i < m; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j)
		{
			if ('I' == s[j])
			{
				me = { i,j };
			}
			g[i][j] = s[j];
		}
		
	}

	dfs(me.first, me.second);
	
	if (0 == ret)
	{
		cout << "TT";
		return 0;
	}


	cout << ret;



	return 0;
}