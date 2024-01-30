#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_set>

using namespace std;

int tarchan;
int maxdepth;

unordered_set<char> banchan;
vector<char> chanlist;

int ret;
string s = "";

void dfs()
{
	if (maxdepth < s.size())
	{
		return;
	}

	if (maxdepth -2 <= s.size() && 0 != s.size())
	{
		int chan;
		chan = stoi(s);
		int pushed = s.size() + abs(tarchan - chan);

		ret = min(ret, pushed);
	}

	for (int i = 0; i < chanlist.size(); ++i)
	{
		s.push_back(chanlist[i]);
		dfs();
		s.pop_back();
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tarchan;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		char c;
		cin >> c;
		banchan.insert(c);
	}


	for (int i = 0; i < 10; ++i)
	{
		if (banchan.end() == banchan.find('0' + i))
		{
			chanlist.push_back('0'+i);
		}
	}

	maxdepth = to_string(tarchan).size()+1;
	ret = 50000001;

	ret = min(abs(100 - tarchan), ret);
	dfs();
	cout << ret;



	return 0;
}