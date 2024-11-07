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

using namespace std;

template <typename T>
void PrintVec(const vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
	}
	cout << endl;
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
		cout << endl;
	}
	cout << endl;
}

/////////////////////////////////////////////
struct TRIE;

bool cmp(TRIE* a, TRIE* b);

struct TRIE
{
	string name;
	vector<TRIE*> child;


	void insert(const vector<string>& origin, int idx)
	{
		if (origin.size() == idx)
		{
			return;
		}

		auto iter = child.begin();
		for (; iter != child.end(); ++iter)
		{
			if (origin[idx] == (*iter)->name)
			{
				break;
			}
		}

		//못찾았을시
		if (child.end() == iter)
		{
			auto newchild = new TRIE;
			newchild->name = origin[idx];
			child.push_back(newchild);
			newchild->insert(origin, idx + 1);
		}
		else
		{
			(*iter)->insert(origin, idx + 1);
		}
	}

	void print(int depth)
	{
		sort(child.begin(), child.end(), cmp);
		for (int i = 0; i < depth; ++i)
		{
			cout << "--";
			//printf("--");
		}
		if ("" != name)
		{
			//cout << endl << name;
			cout << name << endl;
			//printf("%s\n", name.c_str());
		}
		for (const auto& e : child)
		{
			e->print(depth + 1);
		}
	}

};


bool cmp(TRIE* a, TRIE* b)
{
	return a->name < b->name;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;

	int a;
	string s;


	TRIE t;
	for (int i = 0; i < cnt; ++i)
	{
		cin >> a;
		vector<string> origin;
		for (int j = 0; j < a; ++j)
		{
			cin >> s;
			origin.push_back(s);
		}
		t.insert(origin, 0);
	}

	t.print(-1);

	return 0;
}