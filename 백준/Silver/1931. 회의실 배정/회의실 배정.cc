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
struct con
{
	int s;
	int e;
};

bool cmp(const con& a, const con& b)
{
	if (a.s == b.s)
	{
		return a.e < b.e;
	}
	return a.s < b.s;
}

int main()
{
	int n;
	cin >> n;

	int s, e;

	vector<con> confs;
	for (int i = 0; i < n; ++i)
	{
		cin >> s >> e;

		confs.push_back({ s,e });
	}

	sort(confs.begin(), confs.end(), cmp);

	//for (const auto& c : confs)
	//{
	//	cout << c.s << " " << c.e << endl;
	//}

	int ret = 1;
	int curstart = confs[0].s;
	int curend = confs[0].e;

	for (int i = 1; i < confs.size(); ++i)
	{
		if (confs[i].s < curend)
		{
			curend = min(curend, confs[i].e);
			continue;
		}

		++ret;
		curstart = confs[i].s;
		curend = confs[i].e;
	}

	cout << ret;

	return 0;
}