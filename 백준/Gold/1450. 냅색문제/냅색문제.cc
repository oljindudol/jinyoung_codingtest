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
#include <assert.h>

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
vector<long long> fullset;

vector<long long> halfa;
vector<long long> halfb;
int n, c;

vector<long long> createsubsets(vector<long long>& _in)
{
	int sz = _in.size();
	vector<long long> ret;
	ret.reserve(1 << sz);

	for (int i = 0; i < (1 << sz); ++i)
	{
		long long sum = 0;
		for (int j = 0; j < sz; ++j)
		{
			if (i & (1 << j))
			{
				sum += _in[j];
				if (c < sum)
				{
					break;
				}
			}
		}
		if (c >= sum)
			ret.push_back(sum);
	}
	return ret;
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> c;

	int mid = n / 2;
	halfa.resize(mid);
	for (int i = 0; i < mid; ++i)
	{
		cin >> halfa[i];
	}

	halfb.resize(n - mid);
	for (int i = 0; i < (n - mid); ++i)
	{
		cin >> halfb[i];
	}

	auto suba = createsubsets(halfa);
	auto subb = createsubsets(halfb);

	sort(subb.begin(), subb.end());

	long long ret = 0;
	for (long long i = 0; i < suba.size(); ++i)
	{
		long long x = c - suba[i];
		auto ub = upper_bound(subb.begin(), subb.end(), x);
		ret += (ub - subb.begin());
	}
	cout << ret;

	return 0;
}
