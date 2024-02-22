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


int n,l,d;

string target = "";
unordered_set<string> us;


int ret =0;





int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l >> d;


	//n곡
	//길이l
	//알람 d초에 한번씩1초동안
	int max = n* l 
		+ (n-1)*5
		+ 2*d;
	int mu = l;
	int al = 0;
	int rep = 1;

	for (int t = 0; t < max; ++t)
	{
		//곡완료 판정
		if (-5 == mu && rep < n)
		{
			mu = l;
			++rep;
		}
		//알람 설정 판정
		if (-d == al)
		{
			al = 0;
		}


		if (1 > mu && 0 == al)
		{
			cout << t;
			return 0;
		}
		
		--mu;
		--al;
	}



	return 0;
}