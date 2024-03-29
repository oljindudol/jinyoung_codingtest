#include<iostream>
#include<vector>
#include<string>

int enddate;
int maxprofit = 0;
vector<pair<int, int>> vp;

using namespace std;

void dfs(int today, int profit)
{
	if (enddate < today)
	{
		return;
	}
	maxprofit = max(maxprofit, profit);

	//오늘일 접수안함
	dfs(today + 1, profit);
	//오늘일 접수함
	dfs(today + vp[today].first, profit + vp[today].second);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> enddate;

	for (int i = 0; i < enddate; ++i)
	{
		string tmp;
		cin >> tmp;
		vp.push_back({stoi(tmp.substr(0, tmp.find(' '))),
			stoi(tmp.substr(tmp.find(' ') + 1, tmp.size() - tmp.find(' ') - 1) )});



	}



	return 0;
}