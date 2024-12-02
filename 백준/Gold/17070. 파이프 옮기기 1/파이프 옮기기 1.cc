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
int n;
vector<vector<int>> map;

enum orient
{
	hori,
	verti,
	diag,
	o_end,
};

struct nextinfo
{
	int drow;
	int dcol;
	orient shape;
};

vector<vector<nextinfo>> dpos;

bool IsValid(int row, int col, bool IsDiag = false)
{
	if (0 > row || n <= row)
	{
		return false;
	}
	if (0 > col || n <= col)
	{
		return false;
	}
	if (1 == map[row][col])
	{
		return false;
	}

	if (true == IsDiag)
	{
		if (false == IsValid(row - 1, col) || false == IsValid(row, col - 1))
		{
			return false;
		}
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
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			cin >> map[row][col];
		}
	}

	dpos.resize(o_end);

	dpos[hori].push_back({ 0,1 ,hori });
	dpos[hori].push_back({ 1,1 ,diag });

	dpos[verti].push_back({ 1,0 ,verti });
	dpos[verti].push_back({ 1,1 ,diag });

	dpos[diag].push_back({ 0,1,hori });
	dpos[diag].push_back({ 1,0,verti });
	dpos[diag].push_back({ 1,1,diag });

	int ret = 0;

	queue< nextinfo>  q;
	q.push({ 0,1 ,hori });

	while (false == q.empty())
	{
		auto cur = q.front();
		q.pop();


		if (n - 1 == cur.drow && n - 1 == cur.dcol)
		{
			++ret;
			continue;
		}

		for (const auto& next : dpos[cur.shape])
		{
			int newrow = cur.drow + next.drow;
			int newcol = cur.dcol + next.dcol;
			auto s = next.shape;

			if (true == IsValid(newrow, newcol, (diag == s)))
			{
				q.push({ newrow,newcol,s });
			}
		}
	}

	cout << ret;
	return 0;
}