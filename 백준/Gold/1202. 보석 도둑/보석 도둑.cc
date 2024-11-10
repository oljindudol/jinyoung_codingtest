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
struct juwel
{
	int w;
	int v;
	//float e;
};

struct cmp
{
	bool operator()(const juwel& a, const juwel& b)
	{
		return a.v < b.v;
	}
};


bool jsortfunc(const juwel& a, const juwel& b)
{
	//if (a.e == b.e)
	//{
	//	return a.w < b.w;
	//}
	return a.w < b.w;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int jcnt, bcnt;

	cin >> jcnt >> bcnt;
	vector<juwel> juwels(jcnt);
	vector<int> bags(bcnt);
	vector<int> visited(bcnt);
	int w, v;
	for (int i = 0; i < jcnt; ++i)
	{
		cin >> w >> v;
		juwels[i] = { w,v };
	}

	for (int i = 0; i < bcnt; ++i)
	{
		cin >> w;
		bags[i] = w;
	}

	sort(juwels.begin(), juwels.end(), jsortfunc);
	sort(bags.begin(), bags.end());

	priority_queue<juwel, vector<juwel>, cmp> pq;

	long long ret = 0;
	int bagcnt = 0;
	int jidx = 0;
	for (const auto& b : bags)
	{
		for (; jidx < juwels.size(); ++jidx)
		{
			if (b >= juwels[jidx].w)
			{
				pq.push(juwels[jidx]);
			}
			else
			{
				break;
			}
		}

		if (false == pq.empty())
		{
			ret = ret + pq.top().v;
			pq.pop();
		}
	}
	cout << ret;


	return 0;
}

