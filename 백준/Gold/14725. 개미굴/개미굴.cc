#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct room;

struct Trie;

struct room
{
	string name;
	Trie* address;
};

bool cmp(const room& a, const room& b)
{
	return a.name < b.name;
}

struct Trie
{
	vector<room> child;
	bool finish = false;

	void insert(queue<string>& path)
	{
		if (true == path.empty())
		{
			return;
		}

		string cur = path.front();
		path.pop();

		bool findres = false;
		Trie* curadd = nullptr;
		for (auto& e : child)
		{
			if (cur == e.name)
			{
				findres = true;
				curadd = e.address;
				break;
			}
		}
		//만들어주고 정렬
		if (false == findres)
		{
			curadd = new Trie;
			room newroom = { cur,curadd };
			child.push_back(newroom);
			sort(child.begin(), child.end(), cmp);
		}
		curadd->insert(path);
	}

	void PrintChild(int depth = 0)
	{
		if (true == child.empty())
		{
			return;
		}

		for (auto& e : child)
		{
			for (int i = 0; i < depth; ++i)
			{
				cout << "--";
			}
			cout << e.name << endl;
			e.address->PrintChild(depth + 1);
		}
	}
};



int main()
{

	int n;

	cin >> n;

	vector <queue<string>> vecInputs;
	for (int i = 0; i < n; ++i)
	{
		int m;
		cin >> m;
		queue<string> input;
		for (int j = 0; j < m; ++j)
		{
			string tmp;
			cin >> tmp;
			input.push(tmp);
		}
		vecInputs.push_back(input);
	}

	Trie* root = new Trie;

	for (auto& e : vecInputs)
	{
		//while (false == e.empty())
		//{
		//	cout << e.front() << ",";
		//	e.pop();
		//}
		//cout << endl;

		root->insert(e);
	}

	root->PrintChild();


	return 0;
}