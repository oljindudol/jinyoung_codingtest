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

#define MOD 1000000007

struct edge
{
	long long from;
	long long to;
	long long w;
};

long long Init(const vector<long long>& origin, vector<long long>& ST, long long STidx, long long start, long long end)
{
	if (start == end)
	{
		ST[STidx] = origin[start];
		return ST[STidx];
	}

	long long mid = start + (end - start) / 2;
	auto lp = Init(origin, ST, STidx * 2, start, mid) % MOD;
	auto rp = Init(origin, ST, STidx * 2 + 1, mid + 1, end) % MOD;

	auto ret = (lp * rp) % MOD;
	ST[STidx] = ret;
	return ret;
}

void Change(vector<long long>& origin, vector<long long>& ST, long long STidx, long long start, long long end, const long long  OriginIdx, const long long OriginVal)
{
	if (start <= OriginIdx && OriginIdx <= end)
	{
		//case 1
		if (start == end)
		{
			origin[OriginIdx] = OriginVal;
			ST[STidx] = OriginVal;
			return;
		}
		//case 2
		else
		{
			long long mid = start + (end - start) / 2;
			Change(origin, ST, STidx * 2, start, mid, OriginIdx, OriginVal);
			Change(origin, ST, STidx * 2 + 1, mid + 1, end, OriginIdx, OriginVal);

			ST[STidx] = (ST[STidx * 2] * ST[STidx * 2 + 1]) % MOD;
			return;
		}
	}
	//case3
	else
	{
		return;
	}
}

long long Find(vector<long long>& ST, long long STidx, long long start, long long end, const long long left, const long long right)
{
	//case 1
	if (left <= start && end <= right)
	{
		return ST[STidx];
	}
	//case 3
	else if (right< start || left > end)
	{
		return 1;
	}
	//case 2
	{
		long long mid = start + (end - start) / 2;
		auto lp = Find(ST, STidx * 2, start, mid, left, right) % MOD;
		auto rp = Find(ST, STidx * 2 + 1, mid + 1, end, left, right) % MOD;

		long long ret = (lp * rp) % MOD;
		return ret;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<long long> Origin;
	vector<long long> ST;

	// n: 수의 수 m:수의변경 k: 구간곱구하는수
	long long n, m, k;
	cin >> n >> m >> k;
	Origin.resize(n);
	long long h = ceil(log2(n));
	long long tsz = pow(2, h + 1) - 1;
	ST.resize(tsz, 1);

	long long t1, t2, t3;
	for (int i = 0; i < n; ++i)
	{
		cin >> t1;
		Origin[i] = t1;
	}

	//1.ST초기화
	Init(Origin, ST, 1, 0, n - 1);

	for (int i = 0; i < (m + k); ++i)
	{
		cin >> t1 >> t2 >> t3;

		//2. ST변경
		if (1 == t1)
		{
			Change(Origin, ST, 1, 0, n - 1, t2 - 1, t3);
		}
		//3. ST탐색
		else
		{
			long long ret = Find(ST, 1, 0, n - 1, t2 - 1, t3 - 1);
			cout << ret << endl;
			//printf("%ll\n", ret);
		}
	}


	return 0;
}