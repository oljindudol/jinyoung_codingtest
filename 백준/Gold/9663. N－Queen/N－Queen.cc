#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_set>

using namespace std;

int cnt;

vector<int> g;
int ret;

void swap(int& _a, int& _b)
{
	int t = _a;
	_a = _b;
	_b = t;
}

bool dicheck(int _depth)
{
	if (0 == _depth)
	{
		return true;
	}

	for (int i = 0; i < _depth; ++i)
	{
		//0,0
		//1,1
		//2,2
		if ((_depth - i) == (g[_depth] - g[i]))
		{
			return false;
		}

		if ((_depth - i) == (g[i]- g[_depth]))
		{
			return false;
		}
	}
	return true;
}


void dfs(int _depth)
{
	if (_depth == cnt)
	{
		++ret;
		return;
	}

	for (int i = _depth; i < cnt; ++i)
	{
		swap(g[_depth], g[i]);
		if (true == dicheck(_depth))
		{
			dfs(_depth + 1);
		}
		swap(g[_depth], g[i]);
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> cnt;
	
	for (int i = 0; i < cnt; ++i)
	{
		g.push_back(i);
	}

	dfs(0);

	cout << ret;
	return 0;
}