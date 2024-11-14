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
constexpr int INF = 1e3 + 1;
vector<bool> IsPrime;

void init()
{
	IsPrime.resize(INF, true);

	IsPrime[0] = false;
	IsPrime[1] = false;

	for (int i = 2; i < INF; ++i)
	{
		if (false == IsPrime[i])
		{
			continue;
		}

		for (int j = i * i; j < INF; j += i)
		{
			IsPrime[j] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;
	vector<int> cards(n);

	int t;
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		cards[i] = t;
	}

	int retsum = 1e9 + 1;
	int mindiff = 1e9 + 1;
	sort(cards.begin(), cards.end());

	auto iterend = cards.end();
	for (int left = 0; left < n - 2; ++left)
	{
		for (int mid = left + 1; mid < n - 1; ++mid)
		{
			int sum = cards[left] + cards[mid];
			int target = m - sum;
			auto lb = lower_bound(cards.begin() + mid + 1, iterend, target);
			int newidx;
			if (iterend == lb)
			{
				newidx = cards.size() - 1;
			}
			else
			{
				newidx = lb - cards.begin();
				if (target == *lb)
				{
					cout << m;
					return 0;
				}
				else
				{
					--newidx;
					if (mid == newidx)
					{
						continue;
					}
				}
			}
			int newdiff = m - (sum + cards[newidx]);
			if (mindiff > newdiff)
			{
				mindiff = newdiff;
				retsum = sum + cards[newidx];
			}
		}
	}
	cout << retsum;
	return 0;
}

