#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


struct Trie;

#define MAXCNT 26
struct Trie
{
	Trie* child[MAXCNT];
	bool finish;
	Trie() : child{ nullptr }, finish(false) { }
	~Trie()
	{
		for (int i = 0; i < MAXCNT; ++i)
		{
			if (nullptr == child[i])
			{
				continue;
			}
			delete child[i];
			child[i] = nullptr;
		}
	}

	void insert(char* str)
	{
		if (NULL == *str)
		{
			finish = true;
			return;
		}

		int curidx = *str - 'a';
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
			return true;
		}

		if (true == finish)
		{
			return false;
		}

		int curidx = *str - 'a';
		if (nullptr == child[curidx])
		{
			return false;
		}
		char* newstr = str + 1;
		return child[curidx]->find(newstr);

	}


};



int main()
{
	int ret = 0;
	int n, m;

	cin >> n >> m;
	vector<char*> inputs;
	vector<char*> tests;
	char tmpstr[501];

	Trie* root = new Trie;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmpstr;
		root->insert(tmpstr);
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> tmpstr;
		if (root->find(tmpstr))
		{
			++ret;
		}
	}

	delete root;

	cout << ret;
	return 0;
}