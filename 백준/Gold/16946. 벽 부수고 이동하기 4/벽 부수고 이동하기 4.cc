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
constexpr int INF = 2e9 + 1;
int drow[4] = { 1,-1,0,0 };
int dcol[4] = { 0,0,1,-1 };

vector<vector<int>> origin;
vector<vector<int>> newmap;
int id = 1;
int n, m;

struct node
{
	int row;
	int col;
};

bool IsValid(int row, int col, bool secondmode = false)
{
	if (0 > row || n <= row)
	{
		return false;
	}
	if (0 > col || m <= col)
	{
		return false;
	}

	if (true == secondmode)
	{
		return true;
	}

	if (0 != newmap[row][col])
	{
		return false;
	}
	return true;
}

void dfs(int row, int col, int& cnt)
{
	++cnt;
	newmap[row][col] = id;

	for (int i = 0; i < 4; ++i)
	{
		int newrow = row + drow[i];
		int newcol = col + dcol[i];

		if (true == IsValid(newrow, newcol))
		{
			dfs(newrow, newcol, cnt);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	origin.resize(n, vector<int>(m));
	newmap.resize(n, vector<int>(m));

	char t;

	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			cin >> t;
			if ('1' == t)
			{
				origin[row][col] = INF;
				newmap[row][col] = INF;
			}
		}
	}

	vector<int> group;
	group.push_back(0);
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			if (0 == newmap[row][col])
			{
				int cnt = 0;
				dfs(row, col, cnt);
				++id;
				group.push_back(cnt);
			}
		}
	}


	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			if (INF == origin[row][col])
			{
				unordered_set<int> us;
				int newret = 1;
				for (int i = 0; i < 4; ++i)
				{
					int newrow = row + drow[i];
					int newcol = col + dcol[i];

					if (true == IsValid(newrow, newcol, true) && INF != newmap[newrow][newcol])
					{
						us.insert(newmap[newrow][newcol]);
					}

				}
				for (const auto& id : us)
				{
					newret += group[id];
				}
				origin[row][col] = newret;
			}
		}
	}

	for (const auto& r : origin)
	{
		for (const auto& c : r)
		{
			//printf("%d", c);
			cout << c % 10;
		}
		cout << '\n';
		//printf("\n");
	}

	//PrintVec(origin);
	return 0;
}


