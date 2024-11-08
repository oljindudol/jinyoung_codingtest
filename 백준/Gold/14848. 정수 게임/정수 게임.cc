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
long long  target;
vector<long long > nums;
long long ret = 0;

long long getGCD(long long a, long long b)
{
	long long r = b;
	while (0 != r)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long getLCM(long long a, long long b)
{
	long long ret;
	ret = (a * b) / getGCD(a, b);
	return ret;
}

void dfs(long long depth, long long product, long long pickcnt)
{
	//IsPromissing
	if (target < product)
	{
		return;
	}

	if (depth == nums.size())
	{
		if (0 == pickcnt)
		{
			return;
		}
		//홀수일때 -
		if (1 == pickcnt % 2)
		{
			ret = ret - (target / product);
		}
		else
		{
			ret = ret + (target / product);
		}
		return;
	}

	long long lcm = getLCM(product, nums[depth]);
	dfs(depth + 1, lcm, pickcnt + 1);
	dfs(depth + 1, product, pickcnt);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long k;
	cin >> target >> k;
	nums.resize(k);
	long long num;
	for (int i = 0; i < k; ++i)
	{
		cin >> num;
		nums[i] = num;
	}

	ret = target;
	dfs(0, 1, 0);

	cout << ret;

	return 0;
}