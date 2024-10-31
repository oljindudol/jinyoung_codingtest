#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
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

void InitST(const vector<long long>& Origin, vector<long long>& ST, long long STidx, long long start, long long end)
{
	if (start == end)
	{
		ST[STidx] = Origin[start];
		return;
	}
	else
	{
		long long mid = start + (end - start) / 2;
		InitST(Origin, ST, STidx * 2, start, mid);
		InitST(Origin, ST, STidx * 2 + 1, mid + 1, end);
		ST[STidx] = ST[STidx * 2] + ST[STidx * 2 + 1];
	}
}

long long PSum(vector<long long>& ST, long long STidx, long long start, long long end, const long long left, const long long right)
{
	//case 1
	if (left <= start && end <= right)
	{
		return ST[STidx];
	}
	//case 3
	else if (end < left || right < start)
	{
		return 0;
	}

	//case 2
	long long mid = start + (end - start) / 2;
	long long lsum = PSum(ST, STidx * 2, start, mid, left, right);
	long long rsum = PSum(ST, STidx * 2 + 1, mid + 1, end, left, right);

	return lsum + rsum;
}

void Update(vector<long long>& Origin, vector<long long>& ST, long long STidx, long long start, long long end, const long long Oidx, const long long newval)
{
	if (Oidx < start || Oidx > end)
	{
		return;
	}

	if (start == end)
	{
		Origin[Oidx] = newval;
		ST[STidx] = newval;
		return;
	}

	long long mid = start + (end - start) / 2;
	Update(Origin, ST, STidx * 2, start, mid, Oidx, newval);
	Update(Origin, ST, STidx * 2 + 1, mid + 1, end, Oidx, newval);
	ST[STidx] = ST[STidx * 2] + ST[STidx * 2 + 1];
	return;
}


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m, k;
	cin >> n >> m >> k;
	long long testcnt = m + k;
	vector<long long> nums(n);
	long long TreeH = ceil(log(n) / log(2));
	long long TreeSz = pow(2, TreeH + 1) - 1;
	vector<long long> ST(TreeSz);

	//수 입력
	long long tmp;
	for (long long i = 0; i < n; ++i)
	{
		cin >> tmp;
		nums[i] = tmp;
	}

	InitST(nums, ST, 1, 0, n - 1);

	//합구하기,undate
	long long a, b, c;
	for (long long i = 0; i < testcnt; ++i)
	{
		cin >> a >> b >> c;
		//합구하기
		if (2 == a)
		{
			cout << PSum(ST, 1, 0, n - 1, b - 1, c - 1) << endl;
		}
		//update
		else
		{
			Update(nums, ST, 1, 0, n - 1, b - 1, c);
		}
	}

	return 0;
}