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
int tc;

struct employee
{
	int score;
	int interview;
};

bool cmp(const employee& a, const employee& b)
{
	return a.score < b.score;
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	vector<employee> employes;

	int tcnt, emcnt;
	int sc, inter;

	cin >> tcnt;
	for (int test = 0; test < tcnt; ++test)
	{
		cin >> emcnt;

		employes.resize(0);
		employes.resize(emcnt);

		for (int em = 0; em < emcnt; ++em)
		{
			scanf("%d %d", &sc, &inter);
			//cin >> sc >> inter;
			employes[em] = { sc,inter };
		}

		sort(employes.begin(), employes.end(), cmp);

		int ret = 1;
		int mininterview = employes[0].interview;
		for (int cur = 1; cur < employes.size(); ++cur)
		{
			if (mininterview < employes[cur].interview)
			{
			}
			else
			{
				++ret;
			}
			mininterview = min(mininterview, employes[cur].interview);

			//bool IsPass = true;
			//for (int other = 0; other < cur; ++other)
			//{
			//	if (employes[cur].interview > employes[other].interview)
			//	{
			//		IsPass = false;
			//		break;
			//	}
			//}
			//if (true == IsPass)
			//{
			//	++ret;
			//}
		}
		cout << ret << endl;
	}


	return 0;
}