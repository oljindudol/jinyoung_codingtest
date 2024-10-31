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


struct mmpair
{
	int min;
	int max;

};


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


// init find update

//#define INF 1000000001
//#define NINF 0
constexpr int INF = 1000000001;
constexpr int NINF = 0;

void init(const vector<int>& Origin, vector<mmpair>& ST, int STidx, int start, int end)
{
	if (start == end)
	{
		ST[STidx] = { Origin[start],Origin[start] };
		return;
	}

	int mid = start + (end - start) / 2;
	init(Origin, ST, STidx * 2, start, mid);
	init(Origin, ST, STidx * 2 + 1, mid + 1, end);


	ST[STidx] = { min(ST[STidx * 2].min,ST[STidx * 2 + 1].min),max(ST[STidx * 2].max,ST[STidx * 2 + 1].max) };
}

mmpair Find(const vector<mmpair>& ST, int STidx, int start, int end, const int left, const int right)
{
	//case1
	if (left <= start && end <= right)
	{
		return ST[STidx];
	}

	//case3
	if (right < start || left > end)
	{
		return mmpair{ INF,NINF };
	}

	int mid = start + (end - start) / 2;
	//case2
	auto lp = Find(ST, STidx * 2, start, mid, left, right);
	auto rp = Find(ST, STidx * 2 + 1, mid + 1, end, left, right);

	return { min(lp.min,rp.min),max(lp.max,rp.max) };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int a, b;

	cin >> n >> m;
	vector<int> nums(n);

	int STh = ceil(log2(n));
	int STsz = pow(2, STh + 1) - 1;

	vector<mmpair> ST(STsz);

	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		nums[i] = a;
	}
	init(nums, ST, 1, 0, n - 1);


	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;

		auto mmp = Find(ST, 1, 0, n - 1, a - 1, b - 1);

		printf("%d %d\n", mmp.min, mmp.max);
	}


	return 0;
}