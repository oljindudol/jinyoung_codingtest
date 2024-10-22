#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define NCHOOSE 0
#define CHOOSE 1

int main()
{
	//int n;
	//cin >> n;
	string s1;
	string s2;

	cin >> s1 >> s2;

	int l1 = s1.size();
	int l2 = s2.size();

	vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));


	for (int i = 0; i < l1; ++i)
	{
		for (int j = 0; j < l2; ++j)
		{
			if (s1[i] == s2[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else
			{
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	//for (auto& e : dp)
	//{
	//	for (auto& d : e)
	//	{
	//		cout << d << " ";
	//	}
	//	cout << endl;
	//}

	cout << dp[l1][l2];

	return 0;
}