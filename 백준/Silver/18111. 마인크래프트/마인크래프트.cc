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
int r, c, b;
int bcnt;
int bsum = 0;
constexpr int INF = 1e9;
vector<vector<int>> map;

//true일경우 시간출력
int getTime(int target)
{
	if ((bsum + b) < bcnt * target)
	{
		return INF;
	}
	int time = 0;
	for (int row = 0; row < r; ++row)
	{
		for (int col = 0; col < c; ++col)
		{
			int diff = target - map[row][col];
			if (0 == diff)
			{
				continue;
			}
			// target이 커서 블록을 쌓아야하는경우
			else if (0 < diff)
			{
				time += diff;
			}
			else
			{
				time += (abs(diff) * 2);
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
	cin >> r >> c >> b;
	bcnt = r * c;
	map.resize(r, vector<int>(c));

	for (int row = 0; row < r; ++row)
	{
		for (int col = 0; col < c; ++col)
		{
			cin >> map[row][col];
			bsum += map[row][col];
		}
	}

	int minres = INF;
	vector<int> ress(257);
	for (int i = 0; i < 257; ++i)
	{
		ress[i] = getTime(i);
		minres = min(minres, ress[i]);
	}

	cout << minres << ' ';
	for (int i = 256; i >= 0; --i)
	{
		if (minres == getTime(i))
		{
			cout << i;
			return 0;
		}
	}

	return 0;
}