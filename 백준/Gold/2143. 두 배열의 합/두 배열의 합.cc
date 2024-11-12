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
long long t;
//struct node
//{
//	int from;
//	int to;
//	long long psum;
//};
//
//
//bool cmp(const node& a, const node& b)
//{
//	return a.psum < b.psum;
//}


long long ret;

void findret(vector<long long>& shortvec, const vector<long long>& longvec)
{
	int ssz = shortvec.size();
	int lsz = longvec.size();

	sort(shortvec.begin(), shortvec.end());

	for (int i = 0; i < lsz; ++i)
	{
		long long target = t - longvec[i];
		auto ub = upper_bound(shortvec.begin(), shortvec.end(), target);
		auto lb = lower_bound(shortvec.begin(), shortvec.end(), target);

		// lb가 가리키는 값이 target과 같을 때만 카운트
		if (lb != shortvec.end() && *lb == target)
		{
			ret += (ub - lb); // lb와 ub의 차이는 target과 같은 값의 개수
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	int n, m;
	long long tmp;
	cin >> n;
	vector<long long> oa(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		oa[i] = tmp;
	}

	cin >> m;
	vector<long long> ob(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> tmp;
		ob[i] = tmp;
	}

	vector<long long> suma(n);
	vector<long long> psuma;
	//vector<long long> psuma(n * n);

	vector<long long> sumb(m);
	vector<long long> psumb;
	//vector<long long> psumb(m * m);

	suma[0] = oa[0];
	for (int i = 1; i < n; ++i)
	{
		suma[i] = suma[i - 1] + oa[i];
	}

	sumb[0] = ob[0];
	for (int i = 1; i < m; ++i)
	{
		sumb[i] = sumb[i - 1] + ob[i];
	}

	int ida = 0;
	for (int left = -1; left < n - 1; ++left)
	{
		for (int right = left + 1; right < n; ++right)
		{
			if (-1 != left)
			{
				//psuma[ida] = suma[right] - suma[left];
				psuma.push_back(suma[right] - suma[left]);
			}
			else
			{
				psuma.push_back(suma[right]);
				//psuma[ida] = suma[right];
			}
			++ida;
		}
	}

	int idb = 0;
	for (int left = -1; left < m - 1; ++left)
	{
		for (int right = left + 1; right < m; ++right)
		{
			if (-1 != left)
			{
				psumb.push_back(sumb[right] - sumb[left]);
				//psumb[idb] = sumb[right] - sumb[left];
			}
			else
			{
				psumb.push_back(sumb[right]);
				//psumb[idb] = sumb[right];
			}
			++idb;
		}
	}

	n < m ? findret(psuma, psumb) : findret(psumb, psuma);
	cout << ret;

	return 0;
}


