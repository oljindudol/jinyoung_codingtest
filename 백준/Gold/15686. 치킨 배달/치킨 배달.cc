#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
#include <string>
#include <stdio.h>

using namespace std;

int maxdepth;



struct house
{
	int row;
	int col;
	int chikendist;
};

struct chiken
{
	int row;
	int col;
};

#define INFDIST 101
#define INFSOL 10100


int m;
vector <house> houses;
vector <chiken> chikens;
int minsol = INFSOL;

vector<house> RecalcHouses(vector<house> houses, int row, int col)
{
	for (auto& e : houses)
	{
		int newdist = abs(row - e.row) + abs(col - e.col);

		e.chikendist = min(e.chikendist, newdist);
	}
	return houses;
}

void dfs(int depth, int selcnt, vector<house> houses)
{
	if (m == selcnt)
	{
		int distsum = 0;
		for (const auto& h : houses)
		{
			distsum += h.chikendist;
		}
		minsol = min(minsol, distsum);
		return;
	}
	if (depth == chikens.size())
	{
		return;
	}

	//현재 brench가 유망하지 않을경우(남은걸 다선택해도 m보다 작을경우)
	//if (selcnt + chikens.size() - depth < m)
	//{
	//	return;
	//}

	//현재 치킨집을 살릴경우
	dfs(depth + 1, selcnt + 1, RecalcHouses(houses, chikens[depth].row, chikens[depth].col));

	//현재 치킨집을 죽일경우
	dfs(depth + 1, selcnt, houses);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n >> m;

	int num;

	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			cin >> num;
			if (1 == num)
			{
				houses.push_back({ row,col,INFDIST });
			}
			else if (2 == num)
			{
				chikens.push_back({ row,col });
			}
			else
			{
			}
		}
	}

	dfs(0, 0, houses);
	cout << minsol;

	return 0;
}