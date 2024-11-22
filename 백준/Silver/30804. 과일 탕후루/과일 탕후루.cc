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
struct node
{
	int FruitKind;
	int cnt;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int ret = 1;
	vector<node> v;

	cin >> n;
	int prev;
	cin >> prev;
	int pcnt = 1;
	int t;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> t;
		if (t == prev)
		{
			++pcnt;

		}
		else
		{
			v.push_back({ prev, pcnt });
			prev = t;
			pcnt = 1;
		}
	}
	v.push_back({ prev, pcnt });

	int sum = 0;
	vector<int> leftsums(v.size());
	for (int i = v.size() - 1; 0 <= i; --i)
	{
		sum += v[i].cnt;
		leftsums[i] = sum;
	}
	//vector<vector<int>> dp(v.size(), vector<int>(2));
	vector<int> f(10);

	for (int left = 0; left < v.size();)
	{
		//if (ret > leftsums[left])
		//{
		//	break;
		//}
		int fcnt = 1;
		int cnt = v[left].cnt;
		f[v[left].FruitKind] = v[left].cnt;
		ret = max(ret, cnt);
		int right = left + 1;

		while (right < v.size())
		{
			if (0 == f[v[right].FruitKind])
			{
				if (2 == fcnt)
				{
					while (left < right)
					{
						f[v[left].FruitKind] -= v[left].cnt;
						if (0 == f[v[left].FruitKind])
						{
							break;
						}
						else
						{
							++left;
						}
					}
					break;
				}
				++fcnt;
			}
			f[v[right].FruitKind] += v[right].cnt;
			cnt += v[right].cnt;
			//cout << left << ":" << right << ":" << cnt << endl;
			ret = max(ret, cnt);
			++right;
		}
		while (left < v.size() && 0 != f[v[left].FruitKind])
		{
			f[v[left].FruitKind] -= v[left].cnt;
			++left;
		}
		++left;
	}

	cout << ret;
	return 0;
}