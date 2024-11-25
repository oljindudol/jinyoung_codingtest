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
#include <thread>
#include <omp.h>

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
struct node
{
	int row;
	int col;
};

int drow[4] = { 1,-1,0,0 };
int dcol[4] = { 0,0,1,-1 };

int n;
vector<vector<int>> map;

bool IsValid(int row, int col)
{
	if (0 > row || n <= row)
	{
		return false;
	}
	if (0 > col || n <= col)
	{
		return false;
	}
	if (0 == map[row][col])
	{
		return false;
	}
	return true;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	map.resize(n, vector<int>(n));

	vector<int> vecret;

	char t;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			cin >> t;

			if ('1' == t)
			{
				map[row][col] = 1;
			}
		}
	}

	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			int tmp = 0;
			queue<node> q;
			if (false == IsValid(row, col))
			{
				continue;
			}

			q.push({ row,col });
			map[row][col] = 0;
			while (false == q.empty())
			{
				auto cur = q.front();
				q.pop();

				++tmp;

				for (int i = 0; i < 4; ++i)
				{
					int newrow = cur.row + drow[i];
					int newcol = cur.col + dcol[i];

					if (true == IsValid(newrow, newcol))
					{
						map[newrow][newcol] = 0;
						q.push({ newrow,newcol });
					}
				}
			}
			vecret.push_back(tmp);
		}
	}

	string ret = to_string(vecret.size());
	ret += " ";
	sort(vecret.begin(), vecret.end());
	for (const auto& e : vecret)
	{
		ret += to_string(e);
		ret += " ";
	}
	cout << ret;

	return 0;
}