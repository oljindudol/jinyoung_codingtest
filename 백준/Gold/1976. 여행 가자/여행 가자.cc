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

//template <typename T>
//void PrintVec(const vector<T>& vec)
//{
//	for (const auto& e : vec)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//template <typename T>
//void PrintVec(const vector<vector<T>>& vec)
//{
//	for (const auto& e1 : vec)
//	{
//		for (const auto& e2 : e1)
//		{
//			cout << e2 << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}

/////////////////////////////////////////////

class UF
{
private:
	vector<int> m_parent;
	vector<int> m_depth;
	UF();

public:
	UF(int n)
	{
		m_parent.resize(n);
		m_depth.resize(n, 0);

		for (int row = 0; row < n; ++row)
		{
			m_parent[row] = row;
		}
	}

	int Find(int a)
	{
		//if (a == m_parent[a])
		//{
		//	return a;
		//}
		//else
		//{
		//	m_parent[a] = Find(m_parent[a]);
		//}

		while (a != m_parent[a])
		{
			a = m_parent[a];
		}
		return a;
	}

	void Union(int a, int b)
	{
		auto pA = Find(a);
		auto pB = Find(b);

		if (pA == pB) return;

		if (m_depth[pA] == m_depth[pB])
		{
			m_parent[pB] = pA;
			++m_depth[pA];
			return;
		}

		if (m_depth[pA] < m_depth[pB])
		{
			m_parent[pA] = pB;
			return;
		}

		if (m_depth[pB] < m_depth[pA])
		{
			m_parent[pB] = pA;
			return;
		}
	}

};


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	UF uf(n);

	int val;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			cin >> val;
			if (1 == val)
			{
				uf.Union(row, col);
			}
		}
	}

	int t;
	cin >> t;
	auto r = uf.Find(t - 1);

	for (int i = 1; i < m; ++i)
	{
		cin >> t;
		if (r == uf.Find(t - 1))
		{
			continue;
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}