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
long long  n, target;
vector<long long > primes;
long long ret = 0;

void dfs(int depth, long long product, int pickcnt)
{
	//IsPromissing
	if (target < product)
	{
		return;
	}

	if (depth == primes.size())
	{
		if (0 == pickcnt)
		{
			return;
		}

		//홀수면 더해주고 짝수면 빼준다.
		if (1 == pickcnt % 2)
		{
			ret = ret + (target / product);
		}
		else
		{
			ret = ret - (target / product);
		}
		return;
	}

	//선택함
	dfs(depth + 1, product * primes[depth], pickcnt + 1);
	//선택안함
	dfs(depth + 1, product, pickcnt);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//2,3,5배수에서 30은 3번들어감
	//10의배수: 10 20      30
	//6의배수 : 6 12 18 24 30 
	//15의배수 : 15        30

	//30의 배수

	//  1  2  3  4  5 
	//  6  7  8  9 10
	// 11 12 13 14 15
	// 16 17 18 19 20
	// 21 22 23 24 25
	// 26 27 28 29 30

	//숫자 4개일시 a*b*c*d 인숫자는 
	//1개고를때 4C1번들어감+
	//2개고를때 4C2번들어감-
	//3개고를떄 4C3번들어감+
	//4개고를때 4C4번들어감-

	cin >> n >> target;

	long long  t;
	primes.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		primes[i] = t;
	}

	dfs(0, 1, 0);

	cout << ret;

	return 0;
}