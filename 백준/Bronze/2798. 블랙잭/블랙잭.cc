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

	int retsum = 0;
	sort(cards.begin(), cards.end());

	for (int mid = 1; mid < cards.size() - 1; ++mid)
	{
		int left = mid - 1;
		int right = mid + 1;

		while (left >= 0 && right < cards.size())
		{
			int tsum = cards[mid] + cards[left] + cards[right];
			if (tsum <= m)
			{
				retsum = max(retsum, tsum);
				left = mid - 1;
				right = right + 1;
			}
			else
			{
				--left;
			}
		}
	}
	cout << retsum;

	return 0;
}
