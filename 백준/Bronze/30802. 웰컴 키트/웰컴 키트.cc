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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long cnt;
	double s, m, l, xl, xxl, xxxl;
	cin >> cnt >> s >> m >> l >> xl >> xxl >> xxxl;

	double t;
	long long p;
	cin >> t >> p;

	long long sum = 0;
	sum += ceil(s / t);
	sum += ceil(m / t);
	sum += ceil(l / t);
	sum += ceil(xl / t);
	sum += ceil(xxl / t);
	sum += ceil(xxxl / t);

	cout << sum << " ";
	cout << cnt / p << " " << cnt % p;


	return 0;
}

