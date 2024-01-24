#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>


using namespace std;

int input;

bool isprime(int num)
{
	auto to = sqrt(num);
	for (int i = 2; i <= to; ++i)
	{
		if (0 == num % i)
		{
			return false;
		}
	}
	return true;
}

bool ispan(int num)
{
	string t = to_string(num);
	auto sz = t.size();

	for (int i = 0; i < (sz/2); ++i)
	{
		if (t[i] != t[sz - i - 1])
		{
			return false;
		}
	}
	return true;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> input;
	if (1 == input || 2 == input)
	{
		cout << 2;
		return 0;
	}

	if (0 == input % 2)
	{
		++input;
	}

	while (true)
	{
		if (ispan(input) && isprime(input))
		{
			cout<<input;
			return 0;
		}
		else
		{
			input += 2;
		}
	}

	return 0;
}