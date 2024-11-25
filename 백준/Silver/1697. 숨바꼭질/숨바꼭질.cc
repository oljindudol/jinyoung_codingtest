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
	int pos;
	int depth;
};

struct cmp
{
	bool operator()(const node& a, const node& b)
	{
		return a.depth > b.depth;
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	queue<node> q;
	//priority_queue<node, vector<node>, cmp> q;
	vector<bool> visited(100001);
	q.push({ n,0 });

	while (false == q.empty())
	{
		auto cur = q.front();
		//auto cur = q.top();
		q.pop();

		//cout << cur.depth << ": " << cur.pos << endl;

		if (0 > cur.pos || 100000 < cur.pos || true == visited[cur.pos])
		{
			continue;
		}
		visited[cur.pos] = true;

		if (cur.pos == k)
		{
			cout << cur.depth;
			break;
		}

		q.push({ cur.pos - 1 , cur.depth + 1 });
		q.push({ cur.pos + 1 , cur.depth + 1 });
		q.push({ cur.pos * 2 , cur.depth + 1 });
	}

	return 0;
}