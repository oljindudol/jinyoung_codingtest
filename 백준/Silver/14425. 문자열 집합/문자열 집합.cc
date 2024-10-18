#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

constexpr int MAXSZ = 'z' - 'a' + 1;
constexpr int MAXLEN = 501;

struct Trie
{
	Trie* child[MAXSZ] = { nullptr };
	bool finish = false;

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
			if (true == finish)
			{
				return true;
			}
			else
			{
				return false;
			}
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
	int n, m;

	cin >> n >> m;

	Trie* root = new Trie;

	char buffer[MAXLEN];

	for (int i = 0; i < n; ++i)
	{
		cin >> buffer;
		root->insert(buffer);
	}


	int ret = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> buffer;
		if (true == root->find(buffer))
		{
			++ret;
		}
	}

	cout << ret;


	return 0;
}