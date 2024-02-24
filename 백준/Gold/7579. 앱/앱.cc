#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_set>
#include<queue>
#include<stdio.h>
#include<list>

using namespace std;







int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;


	cin >> n >> m;

	//공간=value
	//비활성화 비용=cost
	vector<int> space;
	vector<int> cost;



	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		space.push_back(t);
	}

	int sumcost = 0;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		cost.push_back(t);
		sumcost += t;
	}

	vector<int> pdp(sumcost + 1);
	vector<int> cdp(sumcost + 1);

	pdp[cost[0]] = space[0];

	for (int i = 1; i < n; ++i)
	{
		int cspace = space[i];
		int ccost = cost[i];
		for (int j = 0; j < (sumcost +1); ++j)
		{
			if (j < ccost)
			{
				cdp[j] = pdp[j];
			}
			else
			{
				cdp[j] = max(pdp[j], pdp[j - ccost] + cspace);
			}
		}
		pdp = cdp;
	}



	for (int i = 0; i <pdp.size(); ++i)
	{
		if (m <= pdp[i])
		{
			cout << i;
			break;
		}
	}

	return 0;
}