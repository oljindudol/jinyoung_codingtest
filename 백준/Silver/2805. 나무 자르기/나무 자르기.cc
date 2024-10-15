#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

//input
int treen;
int treelen;
vector<int> treeh;

int leftcutsize;
int rightcutsize;
int retcut;

bool isplus(int cutsize)
{
	//자른 나무의 합을 구함
	long long sum = 0;
	for (auto& h : treeh)
	{
		if (cutsize >= h)
		{
			break;
		}
		sum += (h - cutsize);
	}
	// 합 - 목표길이 의 부호를 판별
	long long remain = sum - treelen;

	if (0 > remain)
		return false;
	return true;
}


void bs(int cutsize)
{
	
	bool plusfirst = isplus(cutsize);
	bool plussecond;
	//충분할떄
	if (true == plusfirst)
	{
		plussecond = isplus(cutsize+1);

		//임계값
		if (false == plussecond)
		{
			retcut = cutsize;
			return;
		}
		else
		{
			rightcutsize = cutsize + 1;
			bs((leftcutsize + rightcutsize) / 2);
		}
	}
	//부족할떄
	else
	{
		plussecond = isplus(cutsize - 1);

		//임계값
		if (true == plussecond)
		{
			retcut = cutsize - 1;
			return;
		}
		else
		{
			leftcutsize = cutsize -1;
			bs((leftcutsize + rightcutsize) / 2);
		}
	}
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> treen >> treelen;

	for (int i = 0; i < treen; ++i)
	{
		string h;
		cin >> h;
		treeh.push_back(stoi(h));
	}

	sort(treeh.begin(),treeh.end(), greater<int>());
	leftcutsize = treeh.front()-1;
	rightcutsize = 0;
	retcut = rightcutsize / 2;

	bs(retcut);

	cout << retcut;
	return 0;
}