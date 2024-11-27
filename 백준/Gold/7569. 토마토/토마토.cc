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
int row, col;
int drow[6] = { 1,-1 ,0,0,0,0 };
int dcol[6] = { 0,0,1,-1,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };
int maxrow, maxcol, maxheight;
vector<vector<vector<int>>> map;

bool IsValid(int row, int col, int h)
{
	if (0 > row || maxrow <= row)
	{
		return false;
	}

	if (0 > col || maxcol <= col)
	{
		return false;
	}
	if (0 > h || maxheight <= h)
	{
		return false;
	}

	if (0 != map[row][col][h])
	{
		return false;
	}
	return true;
}

struct node
{
	int row;
	int col;
	int h;
	int depth;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> maxcol >> maxrow >> maxheight;
	map.resize(maxrow, vector<vector<int>>(maxcol, vector<int>(maxheight)));

	queue<node> q;
	for (int h = 0; h < maxheight; ++h)
	{
		for (int row = 0; row < maxrow; ++row)
		{
			for (int col = 0; col < maxcol; ++col)
			{
				cin >> map[row][col][h];
				if (1 == map[row][col][h])
				{
					q.push({ row,col,h,1 });
				}
			}
		}
	}

	int ret = 1;

	while (false == q.empty())
	{
		auto cur = q.front();
		q.pop();

		//cout << '\n';
		//cout << "//////////////////////////////";
		//cout << '\n';
		//if (ret < cur.depth)
		//{
		//	for (int h = 0; h < maxheight; ++h)
		//	{
		//		for (int row = 0; row < maxrow; ++row)
		//		{
		//			for (int col = 0; col < maxcol; ++col)
		//			{

		//				cout << map[row][col][h] << " ";
		//			}
		//			cout << '\n';
		//		}
		//		cout << '\n';
		//		cout << "////";
		//		cout << '\n';
		//	}
		//}

		ret = max(ret, cur.depth);



		for (int i = 0; i < 6; ++i)
		{
			int nrow = cur.row + drow[i];
			int ncol = cur.col + dcol[i];
			int nh = cur.h + dh[i];

			if (true == IsValid(nrow, ncol, nh))
			{
				map[nrow][ncol][nh] = cur.depth + 1;
				q.push({ nrow,ncol,nh,cur.depth + 1 });
			}
		}
	}

	for (const auto& row : map)
	{
		for (const auto& col : row)
		{
			for (const auto& h : col)
			{
				if (0 == h)
				{
					cout << -1;
					return 0;
				}
			}

		}
	}

	cout << ret - 1;
	return 0;
}