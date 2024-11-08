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

/////////////////////////////////////////////

#define INF 1000000001
vector<int> ST;
vector<int> origin;

void init(int start, int end, int STidx)
{
	if (start == end)
	{
		ST[STidx] = origin[start];
		return;
	}

	int mid = start + (end - start) / 2;
	init(start, mid, STidx * 2);
	init(mid + 1, end, STidx * 2 + 1);

	ST[STidx] = min(ST[STidx * 2], ST[STidx * 2 + 1]);
}

int q(int start, int end, int STidx, const int left, const int right)
{
	if (right < start || left > end)
	{
		return INF;
	}
	else if (left <= start && right >= end)
	{
		return ST[STidx];
	}
	int mid = start + (end - start) / 2;
	int lmin = q(start, mid, STidx * 2, left, right);
	int rmin = q(mid + 1, end, STidx * 2 + 1, left, right);
	return min(lmin, rmin);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int STh = ceil(log2(n + 1));
	int STsz = pow(2, STh + 1) + 1;

	ST.resize(STsz, INF);

	origin.resize(n + 1);
	int t;
	for (int i = 1; i < n + 1; ++i)
	{
		cin >> t;
		origin[i] = t;
	}
	init(1, n, 1);

	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		cout << q(1, n, 1, a, b) << " ";
	}


	return 0;
}