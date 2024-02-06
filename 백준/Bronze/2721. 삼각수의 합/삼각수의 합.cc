#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_set>

using namespace std;

int cnt;
vector<int> input;

int gett(int _in)
{

	return (int)((float)((_in + 2) * (_in + 1)) / 2.f);
}


int getw(int _in)
{
	int ret = 0;
	for (int i = 1; i <= _in; ++i)
	{
		ret += i*gett(i);

	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> cnt;
	
	for (int i = 0; i < cnt; ++i)
	{
		int t;
		cin >> t;
		input.push_back(t);
	}

	for (int i = 0; i < cnt; ++i)
	{
		cout << getw(input[i])<<endl;
	}

	return 0;
}