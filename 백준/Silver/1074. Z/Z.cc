#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
#include <string>
#include <stdio.h>
#include <unordered_map>

using namespace std;

template <typename T>
void PrintVec(const vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
	}
	cout << endl;
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
		cout << endl;
	}
	cout << endl;
}

struct sq
{
	long long w;
	long long h;
	long long a;
};


int gcnt = 0;
int r, c;
bool finish = false;
void dfs(int row, int col, int len)
{
	if (1 == len)
	{
		if (r == row && c == col)
		{
			cout << gcnt;
		}
		++gcnt;
		return;
	}

	int newlen = len / 2;
	int newrow = row + newlen;
	int newcol = col + newlen;
	//pow(newlen,2)의 경우만큼씩 있다.

	int casecnt = pow(newlen, 2);
	if (r < newrow)
	{
		if (c < newcol)
		{
			dfs(row, col, newlen);
		}
		else
		{
			gcnt += casecnt * 1;
			dfs(row, newcol, newlen);
		}
	}
	else
	{
		if (c < newcol)
		{
			gcnt += casecnt * 2;
			dfs(newrow, col, newlen);
		}
		else
		{
			gcnt += casecnt * 3;
			dfs(newrow, newcol, newlen);
		}
	}


}
int main()
{
	int n;

	cin >> n >> r >> c;
	n = pow(2, n);
	//map = vector<vector<int>>(n, vector<int>(n));

	dfs(0, 0, n);

	return 0;
}