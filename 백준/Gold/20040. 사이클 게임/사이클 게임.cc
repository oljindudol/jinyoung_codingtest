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

//template <typename T>
//void PrintVec(const vector<T>& vec)
//{
//	for (const auto& e : vec)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//template <typename T>
//void PrintVec(const vector<vector<T>>& vec)
//{
//	for (const auto& e1 : vec)
//	{
//		for (const auto& e2 : e1)
//		{
//			cout << e2 << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}

/////////////////////////////////////////////


vector<int> vecParents;
vector<int> vecDepth;

void Initialize(int cnt)
{
	vecParents.resize(cnt);
	vecDepth.resize(cnt, 1);

	for (int i = 0; i < cnt; ++i)
	{
		vecParents[i] = i;
	}
}


int Find(int a)
{
	while (a != vecParents[a])
	{
		a = vecParents[a];
	}
	return a;

	//if (a == vecParents[a])
	//{
	//	return a;
	//}
	//else
	//{
	//	vecParents[a] = Find(vecParents[a]);
	//}
}

bool Union(int a, int b)
{
	int ra = Find(a);
	int rb = Find(b);

	if (ra == rb)
	{
		return true;
	}

	if (vecDepth[ra] == vecDepth[rb])
	{
		vecParents[ra] = rb;
		++vecDepth[rb];
		return false;
	}

	if (vecDepth[ra] > vecDepth[rb])
	{
		vecParents[rb] = ra;
		return false;
	}
	if (vecDepth[ra] < vecDepth[rb])
	{
		vecParents[ra] = rb;
		return false;
	}
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	Initialize(n);
	int a, b;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;

		if (true == Union(a, b))
		{
			cout << i + 1;
			return 0;
		}
	}
	cout << 0;

	return 0;
}