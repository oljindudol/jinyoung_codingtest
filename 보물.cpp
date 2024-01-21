#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

//input
int num;
vector<int> a, b;

int ret = 0;

void prosum()
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	for (int i = 0; i < num; ++i)
	{
		ret += a[i] * b[i];
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		vector<int> vt;
		int t;
		cin >> t;
		a.push_back(t);
	}

	for (int i = 0; i < num; ++i)
	{
		vector<int> vt;
		int t;
		cin >> t;
		b.push_back(t);
	}
	prosum();

	cout << ret;
	return 0;
}
