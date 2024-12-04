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
//#include "semaphore.h"
#include <semaphore>

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
#define INF 1e9+1
vector<vector<int>> map;
int n;

void fw()
{
	for (int i = 1; i < n + 1; ++i)
	{
		for (int row = 1; row < n + 1; ++row)
		{
			for (int col = 1; col < n + 1; ++col)
			{
				//if (INF == map[row][i] || INF == map[i][col])
				//{
				//	continue;
				//}

				map[row][col] = min(map[row][col], map[row][i] + map[i][col]);
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	map.resize(n + 1, vector<int>(n + 1, INF));

	int ecnt;
	cin >> ecnt;
	int f, t, w;
	while (ecnt--)
	{
		cin >> f >> t >> w;
		map[f][t] = min(map[f][t], w);
	}


	for (int i = 0; i < n + 1; ++i)
	{
		map[i][i] = 0;
	}


	fw();

	for (int row = 1; row < n + 1; ++row)
	{
		for (int col = 1; col < n + 1; ++col)
		{
			if (INF == map[row][col])
			{
				cout << "0 ";
			}
			else
			{
				cout << map[row][col] << ' ';
			}
		}
		cout << '\n';
	}


	return 0;
}