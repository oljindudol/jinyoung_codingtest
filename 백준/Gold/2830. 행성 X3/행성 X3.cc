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
#include <thread>
#include <omp.h>
#include <mutex>
#include <assert.h>
#include <cstring>

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
vector<int> locals;

string tobi(int num)
{
	string ret = "";

	while (num > 0)
	{
		ret += ('0' + (num % 2));
		num /= 2;
	}

	return ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//int tcnt;
	//cin >> tcnt;

	vector<long long > digitcon(22);
	vector<long long > cnt(22);

	//전처리
	int a = 1;
	for (int i = 0; i < 22; ++i)
	{
		digitcon[i] = a;
		a = a << 1;
	}

	// 입력
	int n;
	cin >> n;
	locals.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> locals[i];
	}

	// 계산
	sort(locals.begin(), locals.end());
	long long ret = 0;
	string first = tobi(locals[0]);
	for (int i = 0; i < first.size(); ++i)
	{
		if ('1' == first[i])
		{
			++cnt[i];
		}
	}
	vector<long long > res(22, 0);

	for (int i = 1; i < n; ++i)
	{
		string bi = tobi(locals[i]);

		for (int j = 0; j < bi.size(); ++j)
		{
			//0이면 1의갯수만큼 res가산
			if ('0' == bi[j])
			{
				res[j] += cnt[j];
			}
			else
			{
				res[j] += (i - cnt[j]);
				++cnt[j];
			}
		}
	}

	for (int i = 0; i < 22; ++i)
	{
		ret += (res[i] * digitcon[i]);
	}


	//출력
	cout << ret;

	return 0;
}
