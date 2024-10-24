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

int n, s;



int main()
{
	cin >> n >> s;

	vector<int> nums;
	int tmp;


	int idx = -1;
	int tosum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		nums.push_back(tmp);
		tosum += tmp;
	}

	if (s > tosum)
	{
		cout << 0;
		return 0;
	}

	int left = 0;
	int psum = 0;
	int curlen = 0;
	int minlen = 100001;

	for (int right = 0; right < n; ++right)
	{
		psum = psum + nums[right];
		++curlen;

		//psum이크면 
		while (s <= psum && left <= right)
		{
			//cout << "left: " << left << "right" << right << psum endl;
			minlen = min(minlen, curlen);

			psum -= nums[left];
			++left;
			--curlen;
		}
	}

	cout << minlen;

	return 0;
}