#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <ostream>

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
/////////////////////////////////////////////
/////////////////////////////////////////////

class UF
{
public:
	vector<int> m_parents;
	vector<int> m_rank;


private:
	UF();

public:
	UF(int n)
	{
		m_parents = vector<int>(n + 1);
		//m_rank = vector<int>(n + 1);

		for (int i = 0; i < n + 1; ++i)
		{
			m_parents[i] = i;
			//m_rank[i] = 0;
		}
	}

	int Find(int a)
	{

		while (a != m_parents[a])
		{
			a = m_parents[a];
		}

		return a;
	}

	void Union(int a, int b)
	{
		int aRoot = Find(a);
		int bRoot = Find(b);

		if (aRoot == bRoot) return;

		m_parents[bRoot] = aRoot;
	}

	//bool Union(int a, int b)
	//{
	//	int aRoot = Find(a);
	//	int bRoot = Find(b);

	//	if (aRoot == bRoot) return false;

	//	if (m_rank[aRoot] == m_rank[bRoot])
	//	{
	//		m_parents[bRoot] = aRoot;
	//		++m_rank[aRoot];
	//		return true;
	//	}

	//	if (m_rank[aRoot] < m_rank[bRoot])
	//	{
	//		m_parents[aRoot] = bRoot;
	//		return true;
	//	}
	//	else if (m_rank[aRoot] > m_rank[bRoot])
	//	{
	//		m_parents[bRoot] = aRoot;
	//		return true;
	//	}

	//	return false;
	//}

};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, n;

	int c, a, b;

	cin >> n >> m;

	UF uf(n);
	for (int i = 0; i < m; ++i)
	{
		cin >> c >> a >> b;

		if (0 == c)
		{
			uf.Union(a, b);
			continue;
		}
		else
		{
			auto aroot = uf.Find(a);
			auto broot = uf.Find(b);

			if (aroot == broot)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}