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
vector<vector<long long>> map;
long long maxrow, maxcol, b;
long long blockcnt;
long long sum;
constexpr long long subtime = 2;
constexpr long long addtime = 1;

long long IsPossible(long long targetheight)
{
	if (sum + b < targetheight * blockcnt)
	{
		return 2e9 + 1;
	}
	long long time = 0;

	for (int row = 0; row < maxrow; ++row)
	{
		for (int col = 0; col < maxcol; ++col)
		{
			long long needwork = targetheight - map[row][col];
			if (0 > needwork)
			{
				time += (-needwork * subtime);
			}
			else
			{
				time += (needwork * addtime);
			}
		}
	}
	return time;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> maxrow >> maxcol >> b;
	blockcnt = maxrow * maxcol;
	map.resize(maxrow, vector<long long>(maxcol));

	for (int row = 0; row < maxrow; ++row)
	{
		for (int col = 0; col < maxcol; ++col)
		{
			cin >> map[row][col];
			sum += map[row][col];
		}
	}

	long long left = sum / blockcnt;
	long long right = (sum + b) / blockcnt + 1;
	long long rettime = 2e9 + 1;

	for (long long i = right; 0 <= i; --i)
	{
		long long can = IsPossible(i);
		//cout << can << " " << right << "\n";
		if (rettime > can)
		{
			rettime = can;
			right = i;
		}
	}

	//while (left <= right)
	//{
	//	long long mid = left + (right - left) / 2;
	//	auto res = IsPossible(mid);

	//	if (rettime >= res)
	//	{
	//		left = mid + 1;
	//		rettime = res;
	//	}
	//	else
	//	{
	//		right = mid - 1;
	//	}
	//}

	cout << rettime << " " << right;

	return 0;
}