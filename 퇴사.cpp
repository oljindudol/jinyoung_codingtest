#include<iostream>
#include<vector>
#include<string>


using namespace std;

int enddate;
int maxprofit = 0;
vector<pair<int, int>> vp;

void dfs(int today, int profit)
{
	if (enddate < today)
	{
		return;
	}

	maxprofit = max(maxprofit, profit);

	if (enddate == today)
	{
		return;
	}
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
		string d, p;
		cin >> d >> p;
		vp.push_back({ stoi(d),
			stoi(p) });
	}

	dfs(0, 0);
	cout << maxprofit;
	return 0;
}