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

int n, m;

#define INF 300 000 001

int main()
{
	cin >> n >> m;

	vector<int> nums;
	int newright;

	int left = 0;
	int psum = 0;
	int comb = 0;

	for (int right = 0; right < n; ++right)
	{
		cin >> newright;
		nums.push_back(newright);

		psum += newright;
		while (m <= psum && left <= right)
		{
			if (m == psum)
			{
				++comb;
			}

			psum -= nums[left];
			++left;
		}
	}



	cout << comb;

	return 0;
}