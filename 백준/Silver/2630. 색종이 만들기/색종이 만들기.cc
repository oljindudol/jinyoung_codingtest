#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <ostream>
#include <stack>
#include <unordered_set>
#include <sstream>
#include <list>

using namespace std;

template <typename T>
void PrintVec(const vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
	}
	cout << '\n';
}


template <typename T>
void PrintVec(const vector<vector<T>>& vec)
{
	for (const auto& e1 : vec)
	{
		for (const auto& e2 : e1)
		{
			cout << e2 << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

/////////////////////////////////////////////
enum COLOR
{
	WHITE,
	BLUE,
	END,
};
int n;
vector<vector<COLOR>> map;

int retwhite = 0;
int retblue = 0;

COLOR dfs(int row, int col, int len)
{
	if (1 == len)
	{
		return map[row][col];
	}

	int hlen = len / 2;
	COLOR res[4];

	res[0] = dfs(row, col, hlen);
	res[1] = dfs(row + hlen, col, hlen);
	res[2] = dfs(row, col + hlen, hlen);
	res[3] = dfs(row + hlen, col + hlen, hlen);

	//모두 같을 경우
	if (res[0] == res[1] && res[1] == res[2] && res[2] == res[3])
	{
		return res[0];
	}

	//다를경우
	for (int i = 0; i < 4; ++i)
	{
		if (WHITE == res[i])
		{
			++retwhite;
			continue;
		}
		if (BLUE == res[i])
		{
			++retblue;
			continue;
		}
	}
	return END;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	map.resize(n, vector<COLOR>(n, WHITE));

	int t;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			cin >> t;
			if (BLUE == t)
			{
				map[row][col] = BLUE;
			}
		}
	}

	int fin = dfs(0, 0, n);
	if (BLUE == fin)
	{
		++retblue;
	}
	if (WHITE == fin)
	{
		++retwhite;
	}

	cout << retwhite << " ";
	cout << retblue;

	return 0;
}