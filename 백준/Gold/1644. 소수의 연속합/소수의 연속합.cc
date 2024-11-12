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
long long  c;
long long  id = 0;
vector<long long > dp;
vector<long long > primes;


void initdp()
{
	dp.resize(c + 1, -1);

	//dp[2] = 0;
	//primes.push_back(2);
	//dp[3] = 1;
	//primes.push_back(3);

	for (int i = 2; i < c + 1; ++i)
	{
		if (-1 != dp[i])
		{
			continue;
		}
		primes.push_back(i);
		for (int j = i * 2; j < c + 1; j += i)
		{
			//if (-1 != dp[j])
			//{
			//	continue;
			//}
			dp[j] = id;
		}
		++id;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> c;

	if (1 == c)
	{
		cout << 0;
		return 0;
	}

	initdp();

	long long psum = primes[0];
	long long right = 0;
	long long  ret = 0;
	for (int left = 0; left < primes.size(); ++left)
	{
		//if (right - left < 1)
		//{
		//	continue;
		//}

		while (psum <= c && right < primes.size())
		{
			if (c == psum)
			{
				++ret;
			}

			++right;
			if (right < primes.size())
			{
				psum = psum + primes[right];
			}
		}
		psum = psum - primes[left];
	}

	cout << ret;
	return 0;
}


