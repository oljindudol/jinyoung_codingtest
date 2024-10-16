#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


struct Trie;

#define MAXCNT 10
struct Trie
{
	Trie* child[MAXCNT] = { nullptr };
	bool finish = false;

	void insert(char* str)
	{
		if (NULL == *str)
		{
			finish = true;
			return;
		}

		int curidx = *str - '0';
		if (nullptr == child[curidx])
		{
			child[curidx] = new Trie;
		}

		char* newstr = str + 1;
		child[curidx]->insert(newstr);
	}

	bool find(char* str)
	{
		if (NULL == *str)
		{
			return false;
		}

		if (true == finish)
		{
			return true;
		}

		int curidx = *str - '0';
		if (nullptr == child[curidx])
		{
			return false;
		}
		char* newstr = str + 1;
		return child[curidx]->find(newstr);
	}
};

char input[11];

int main()
{
	int t, n;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		Trie* root = new Trie;
		vector<string> inputs;

		int n;
		cin >> n;

		for (int j = 0; j < n; ++j)
		{
			cin >> input;
			inputs.push_back(input);
			root->insert(input);
		}

		bool valid = true;
		for (auto& e : inputs)
		{
			if (true == root->find((char*)e.c_str()))
			{
				valid = false;
				break;
			}
		}

		if (true == valid)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}