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
struct line
{
	int start;
	int end;
};

bool cmp(const line& a, const line& b)
{
	if (a.start == b.start)
	{
		return a.end < b.end;
	}
	return a.start < b.start;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int lcnt;
	int s, e;

	cin >> lcnt;
	vector<line> vecline(lcnt);

	for (int i = 0; i < lcnt; ++i)
	{
		cin >> s >> e;
		vecline[i] = { s,e };
	}

	sort(vecline.begin(), vecline.end(), cmp);

	int sum = 0;

	int left = vecline[0].start;
	int right = vecline[0].end;
	sum += (right - left);

	for (int i = 1; i < vecline.size(); ++i)
	{
		// left start  right    end
		if (vecline[i].start <= right)
		{
			int diff = vecline[i].end - right;
			if (diff > 0)
			{
				sum += diff;
				right = vecline[i].end;
				continue;
			}
			else
			{
				continue;
			}
		}
		// left right start end
		else
		{
			left = vecline[i].start;
			right = vecline[i].end;
			sum += (right - left);
		}
	}

	printf("%d", sum);

	return 0;
}