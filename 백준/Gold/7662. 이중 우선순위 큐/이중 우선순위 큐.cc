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
#include <list>
#include <thread>
#include <omp.h>

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
struct node
{
	int val;
	int id;
};

struct cmpgreater
{
	bool operator()(const node& a, const node& b)
	{
		return a.val < b.val;
	}
};

struct cmplesser
{
	bool operator()(const node& a, const node& b)
	{
		return a.val > b.val;
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tcnt;
	cin >> tcnt;

	char t;
	int i;
	while (tcnt--)
	{
		int n;
		cin >> n;

		int id = 0;
		priority_queue<node, vector<node>, cmpgreater> gpq;
		priority_queue < node, vector<node>, cmplesser> lpq;
		unordered_set<int> us_deleted;

		while (n--)
		{
			cin >> t;
			cin >> i;
			if ('I' == t)
			{
				gpq.push({ i,id });
				lpq.push({ i,id });
				++id;
			}
			else
			{
				if (i == 1)
				{
					while (false == gpq.empty())
					{
						auto cur = gpq.top();
						gpq.pop();

						if (us_deleted.end() == us_deleted.find(cur.id))
						{
							us_deleted.insert(cur.id);
							break;
						}
					}
				}
				else
				{
					while (false == lpq.empty())
					{
						auto cur = lpq.top();
						lpq.pop();

						if (us_deleted.end() == us_deleted.find(cur.id))
						{
							us_deleted.insert(cur.id);
							break;
						}
					}
				}
			}
		}
		bool bfound = false;
		int gval;
		int lval;
		while (false == gpq.empty())
		{
			auto cur = gpq.top();
			gpq.pop();

			if (us_deleted.end() == us_deleted.find(cur.id))
			{
				bfound = true;
				gval = cur.val;
				break;
			}
		}
		if (true == bfound)
		{
			while (false == lpq.empty())
			{
				auto cur = lpq.top();
				lpq.pop();

				if (us_deleted.end() == us_deleted.find(cur.id))
				{
					lval = cur.val;
					break;
				}
			}
			cout << gval << " " << lval << " ";
		}
		else
		{
			cout << "EMPTY" << " ";
		}
	}






	return 0;
}