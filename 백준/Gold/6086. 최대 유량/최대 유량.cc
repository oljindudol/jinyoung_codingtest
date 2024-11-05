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

#define INF 100000

vector<vector<int>> edges(128);
vector<vector<int>> cap(128, vector<int>(128, 0));
vector<vector<int>> flow(128, vector<int>(128, 0));
vector<int> visited;

int ret = 0;

int START = 'A';
int END = 'Z';

void maxFlow()
{
	int from = START;

	while (true)
	{
		visited.clear();
		visited.resize(128, -1);
		queue<int> q;
		q.push(START);

		while (false == q.empty())
		{
			int from = q.front();
			q.pop();

			for (const auto& e : edges[from])
			{
				int to = e;
				if (cap[from][to] - flow[from][to] > 0 && visited[to] == -1)
				{
					q.push(to);
					visited[to] = from;
					if (END == to)
					{
						break;
					}
				}
			}
		}

		if (-1 == visited[END])
		{
			break;
		}

		int minflow = INF;

		for (int i = END; i != START; i = visited[i])
		{
			minflow = min(minflow, cap[visited[i]][i] - flow[visited[i]][i]);
		}

		for (int i = END; i != START; i = visited[i])
		{
			flow[visited[i]][i] += minflow;
			flow[i][visited[i]] -= minflow;
		}
		ret += minflow;
	}
}

int main()
{

	int cnt;
	cin >> cnt;

	char f, t;
	int c;

	for (int i = 0; i < cnt; ++i)
	{
		cin >> f >> t >> c;
		edges[f].push_back(t);
		edges[t].push_back(f);
		cap[f][t] += c;
		cap[t][f] += c;
	}

	maxFlow();

	cout << ret;
	return 0;
}