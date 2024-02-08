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

	int cnt, blength,wlimit;

	list<int> trw;

	cin >> cnt >> blength >> wlimit;

	for (int i = 0; i < cnt; ++i)
	{
		int t; 
		cin >> t;
		trw.push_back(t);
	}


	//다리위 현재 무게
	int curbw = 0;
	//리턴용
	int ret = 0;
	//다리위 트럭 위치 무게,위치
	list<pair<int,int>> l;


	//프로그램끝판단
	while (!trw.empty() || !l.empty())
	{
		++ret;

		//트럭밀어주기
		bool poptrig = false;
		for (auto& e : l)
		{
			++e.second;
			if (blength < e.second)
			{
				curbw -= e.first;
				poptrig = true;
			}
		}

		//트럭 빼주기 판단
		if (true == poptrig)
		{
			l.pop_front();
		}

		//트럭넣어주기판단(현재총무게)
		if (trw.empty())
			continue;

		int tf = trw.front();
		if (wlimit >= (curbw +tf))
		{
			l.push_back({ tf,1 });
			curbw += tf;
			trw.pop_front();
		}
	}

	cout << ret;

	return 0;
}