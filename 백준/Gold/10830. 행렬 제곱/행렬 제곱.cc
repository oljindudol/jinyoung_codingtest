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
vector<vector<long long>> mat;
int n;
#define MOD 1000

vector<vector<long long>> mult(const vector<vector<long long>>& a, const vector<vector<long long>>& b)
{
	vector<vector<long long>> ret(n, vector<long long>(n));

	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			for (int i = 0; i < n; ++i)
			{
				ret[row][col] += (a[row][i] * b[i][col]);
				ret[row][col] = ret[row][col] % MOD;
			}
		}
	}
	return ret;
}


vector<vector<long long>> dc(const vector<vector<long long>>& a, const long long r)
{
	vector<vector<long long>> ret(n, vector<long long>(n));
	if (1 == r)
	{
		return a;
	}


	if (1 == r % 2)
	{
		auto mid = dc(a, (r - 1) / 2);
		ret = mult(a, mid);
		ret = mult(ret, mid);
	}
	else
	{
		auto mid = dc(a, r / 2);
		ret = mult(mid, mid);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long r;
	cin >> n >> r;
	mat.resize(n, vector<long long>(n));
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			cin >> mat[row][col];
			mat[row][col] %= MOD;
		}
	}

	auto ret = dc(mat, r);

	PrintVec(ret);

	return 0;
}
