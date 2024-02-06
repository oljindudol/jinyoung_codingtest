#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_set>

using namespace std;

int cnt;

vector<bool> vs;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k, b;
	cin >> cnt>>k>>b;
	vs.resize(cnt, true);


	for (int i = 0; i < b; ++i)
	{
		int input;
		cin >> input;
		vs[input - 1] = false;
	}

	int cur = 0;
	int ret;

	//초기화
	for (int i = 0; i < k; ++i)
	{
		if (false == vs[i])
		{
			++cur;
		}
	}

	ret = cur;

	//슬윈
	for (int i = k; i < cnt; ++i)
	{
		if (false == vs[i])
		{
			++cur;
		}

		if (false == vs[i - k])
		{
			--cur;

			ret = min(ret, cur);
		}
	}


	cout << ret;

	return 0;
}