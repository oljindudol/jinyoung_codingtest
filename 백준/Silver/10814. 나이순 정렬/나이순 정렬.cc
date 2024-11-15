#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <ostream>
#include <stack>
#include <unordered_set>
#include <sstream>

using namespace std;

template <typename T>
void PrintVec(const vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
	}
	cout << '\n';
}


template <typename T>
void PrintVec(const vector<vector<T>>& vec)
{
	for (const auto& e1 : vec)
	{
		for (const auto& e2 : e1)
		{
			cout << e2 << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

/////////////////////////////////////////////
struct user
{
	int age;
	string name;
	int idx;
};

bool cmp(const user& a, const user& b)
{
	if (a.age == b.age)
	{
		return a.idx < b.idx;
	}
	return a.age < b.age;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;

	vector<user> users(cnt);
	for (int i = 0; i < cnt; ++i)
	{
		cin >> users[i].age >> users[i].name;
		users[i].idx = i;
	}

	sort(users.begin(), users.end(), cmp);

	for (const auto& e : users)
	{
		cout << e.age << " " << e.name << " ";
	}


	return 0;
}
