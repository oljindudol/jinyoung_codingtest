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
int sccid = 0;
int id = 0;
int sccnum = 0;
vector<vector<int>> edges;

vector<int> parents;

stack<int> s;
vector<bool> finished;

vector<int> getscc;


struct SCC
{
	int in;
	int out;
	vector<int> compnents;
};
vector<SCC> SCCs;

// parents배열의 역할
// 1. 방문체크
// 2. 자기자신 초기id기억
// 3. 갈수있는 엣지중 가장 빨리 방문한 엣지 판별

// parent변수 역할
// 1.갈수있는 edge중 가장 빠른 edge return(재귀)

int dfs(int from)
{
	//cout << from << " ";
	parents[from] = ++id;
	s.push(from);

	//1. 정점from과 인접한 정점들의 부모노드를 결정
	// 사이클이 돌면(1->2->3->1 같은경우)
	//dfs의 호출 1-1을 멈추고 1-2번을 체크후 밑의 2번과정을 실행하게됨.
	int parent = parents[from];

	for (const auto& e : edges[from])
	{
		int to = e;
		// 1-1 아직 방문하지않은 정점from의 이웃정점들
		if (0 == parents[to])
		{
			parent = min(parent, dfs(to));
		}
		// 1-2 방문은 했으나 아직 scc로 추출되지않은 정점x의 이웃정점들
		else if (false == finished[to])
		{
			parent = min(parent, parents[to]);
		}
	}

	// 찾은 부모노드가 자기자신인경우
	if (parent == parents[from])
	{
		SCC scc = {};
		while (true)
		{
			int to = s.top();
			s.pop();
			scc.compnents.push_back(to);
			finished[to] = true;
			getscc[to] = sccid;
			if (to == from) break; //자기자신이 나오면 멈춤
		}
		++sccid;
		SCCs.push_back(scc);
	}
	return parent;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tcnt;
	cin >> tcnt;

	int n, m;
	int f, t;
	for (int i = 0; i < tcnt; ++i)
	{
		cin >> n >> m;

		sccid = 0;
		id = 0;

		SCCs.resize(0);
		finished.resize(0);
		finished.resize(n + 1);
		edges.resize(0);
		edges.resize(n + 1);
		parents.resize(0);
		parents.resize(n + 1);

		getscc.resize(0);
		getscc.resize(n + 1, -1);
		s = stack<int>();

		for (int j = 0; j < m; ++j)
		{
			cin >> f >> t;
			edges[f].push_back(t);
		}

		for (int j = 1; j < n + 1; ++j)
		{
			if (0 != parents[j])
			{
				continue;
			}
			dfs(j);
		}

		//vector<vector<int>> sccedges(sccid + 1);

		for (int from = 1; from < n + 1; ++from)
		{
			for (const auto& to : edges[from])
			{
				int sccfrom = getscc[from];
				int sccto = getscc[to];
				if (sccfrom != sccto)
				{
					//sccedges[sccfrom].push_back(sccto);
					++SCCs[sccfrom].out;
					++SCCs[sccto].in;
				}
			}
		}

		int ret = 0;
		for (const auto& scc : SCCs)
		{
			if (0 == scc.in)
			{
				++ret;
				//ret += scc.out;
			}
		}

		//PrintVec(getscc);

		printf("%d\n", ret);
	}


	return 0;
}