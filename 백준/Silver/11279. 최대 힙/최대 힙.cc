#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_set>
#include<queue>
#include<stdio.h>

using namespace std;

int cnt;

vector<bool> vs;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> cnt;

	priority_queue<int> pq;
	vector<int> input;

	for (int i = 0; i < cnt; ++i)
	{
		int t;
		cin >> t;
		input.push_back(t);
	}



	for (int i = 0; i < cnt; ++i)
	{
		auto& t = input[i];

		if (0 == t)
		{
			if (pq.empty())
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n",pq.top());
				pq.pop();
			}

		}
		else
		{
			pq.push(t);
		}
	}



	return 0;
}