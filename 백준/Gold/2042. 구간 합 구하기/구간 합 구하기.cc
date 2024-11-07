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

void update(long long  idx, long long  val, vector<long long >& pw)
{
	while (idx < pw.size())
	{
		pw[idx] += val;
		idx = idx + (idx & -idx);
	}
}

long long sum(long long  idx, vector<long long >& pw)
{
	long long ret = 0;

	while (0 < idx)
	{
		ret += pw[idx];
		idx = idx - (idx & -idx);
	}

	return ret;
}

long long q(long long  s, long long  e, vector<long long >& pw)
{
	return sum(e, pw) - sum(s - 1, pw);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long  n, m, k;
	cin >> n >> m >> k;

	++n;

	vector<long long> origin(n);
	vector<long long> pw(n);

	long long t;
	for (long long i = 1; i < n; ++i)
	{
		cin >> t;
		origin[i] = t;
	}

	//초기화
	for (long long i = 1; i < n; ++i)
	{
		update(i, origin[i], pw);
	}

	//t1 : 1 바꾸기 2.구간합
	long long  t1, t2, t3;
	for (long long i = 0; i < (m + k); ++i)
	{
		cin >> t1 >> t2 >> t3;

		if (1 == t1)
		{
			long long  diff = t3 - origin[t2];
			origin[t2] = t3;
			update(t2, diff, pw);
		}
		else
		{
			long long res = q(t2, t3, pw);
			cout << res << " ";
		}
	}


	return 0;
}