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
int getMinChange(int srow, int scol, const vector<vector<char>>& origin)
{
	bool rwhite = true;
	bool cwhite;

	int w = 0;
	int b = 0;
	for (int row = srow; row < srow + 8; ++row)
	{
		cwhite = rwhite;
		for (int col = scol; col < scol + 8; ++col)
		{
			if (true == cwhite)
			{
				if ('W' == origin[row][col])
				{
					++b;
				}
				else
				{
					++w;
				}
			}
			if (false == cwhite)
			{
				if ('B' == origin[row][col])
				{
					++b;
				}
				else
				{
					++w;
				}
			}
			cwhite = !cwhite;
		}
		rwhite = !rwhite;
	}
	return min(w, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int maxrow, maxcol;
	cin >> maxrow >> maxcol;

	vector<vector<char>> origin(maxrow, vector<char>(maxcol));
	char t;
	for (int row = 0; row < maxrow; ++row)
	{
		for (int col = 0; col < maxcol; ++col)
		{
			cin >> t;
			origin[row][col] = t;
		}
	}

	int mn = 2501;
	for (int row = 0; row < maxrow - 7; ++row)
	{
		for (int col = 0; col < maxcol - 7; ++col)
		{
			int newmin = getMinChange(row, col, origin);
			//cout << newmin;
			mn = min(mn, newmin);
		}
	}
	cout << mn;

	return 0;
}
