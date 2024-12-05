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
#include <mutex>
//#include "semaphore.h"
#include <semaphore>

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
int dccwrow[4] = { 0,-1,0,1 };
int dcol[4] = { 1,0,-1,0 };

int ret = 0;
int r, c;
vector<vector<int>> map;

bool IsValid(int row, int col, bool accheck = true)
{
	if (0 > row || r <= row)
	{
		return false;
	}
	if (0 > col || c <= col)
	{
		return false;
	}

	if (false == accheck)
	{
		return true;
	}

	if (-1 == map[row][col])
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
	int t;
	cin >> r >> c >> t;
	vector<int> ac;

	map.resize(r, vector<int>(c));
	for (int row = 0; row < r; ++row)
	{
		for (int col = 0; col < c; ++col)
		{
			cin >> map[row][col];
			if (-1 == map[row][col])
			{
				ac.push_back(row);
			}
		}
	}

	vector<vector<int>> nmap;
	while (t--)
	{
		//확산
		nmap.resize(0, vector<int>(0));
		nmap.resize(r, vector<int>(c));

		for (int row = 0; row < r; ++row)
		{
			for (int col = 0; col < c; ++col)
			{
				if (0 == map[row][col])
				{
					continue;
				}

				if (-1 == map[row][col])
				{
					nmap[row][col] = -1;
					continue;
				}

				int cnt = 0;
				int newval = map[row][col] / 5;
				for (int i = 0; i < 4; ++i)
				{
					int nrow = row + dccwrow[i];
					int ncol = col + dcol[i];

					if (true == IsValid(nrow, ncol))
					{
						++cnt;
						nmap[nrow][ncol] += newval;
					}
				}
				nmap[row][col] += (map[row][col] - (newval * cnt));
			}
		}

		map = nmap;
		//ccw공청
		int curstate = 0;
		int currow = ac[0];
		int curcol = 0;
		int prevdust = 0;
		while (true)
		{
			int nrow = currow + dccwrow[curstate];
			int ncol = curcol + dcol[curstate];
			if (false == IsValid(nrow, ncol, false))
			{
				++curstate;
				nrow = currow + dccwrow[curstate];
				ncol = curcol + dcol[curstate];
			}
			if (-1 == map[nrow][ncol])
			{
				break;
			}
			int t = map[nrow][ncol];
			map[nrow][ncol] = prevdust;
			currow = nrow;
			curcol = ncol;
			prevdust = t;
		}


		//cw공청
		curstate = 0;
		currow = ac[1];
		curcol = 0;
		prevdust = 0;
		while (true)
		{
			int nrow = currow - dccwrow[curstate];
			int ncol = curcol + dcol[curstate];
			if (false == IsValid(nrow, ncol, false))
			{
				++curstate;
				nrow = currow - dccwrow[curstate];
				ncol = curcol + dcol[curstate];
			}
			if (-1 == map[nrow][ncol])
			{
				break;
			}
			int t = map[nrow][ncol];
			map[nrow][ncol] = prevdust;
			currow = nrow;
			curcol = ncol;
			prevdust = t;
		}
	}

	ret = 0;
	for (const auto& row : map)
	{
		for (const auto& col : row)
		{
			if (-1 == col)
			{
				continue;
			}
			ret += col;
		}
	}

	cout << ret;
	return 0;
}