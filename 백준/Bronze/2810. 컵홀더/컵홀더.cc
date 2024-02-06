#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_set>

using namespace std;

int cnt;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> cnt;
	
	string c;
	cin >> c;

	int ret = cnt + 1;

	for (int i = 0; i < cnt; ++i)
	{
		if ('L' == c[i])
		{
			--ret;
			++i;
		}
		
	}

	if (cnt < ret)
	{
		--ret;
	}

	cout << ret;

	return 0;
}