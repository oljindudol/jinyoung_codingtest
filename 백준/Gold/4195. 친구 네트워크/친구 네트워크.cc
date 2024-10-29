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
	unordered_map<string, string> um_Parents;
	unordered_map<string, int> um_Depth;
	unordered_map<string, int> um_ChildCnt;


public:
	void Insert(const string& name)
	{
		if ("" == um_Parents[name])
		{
			um_Parents[name] = name;
			um_Depth[name] = 1;
			um_ChildCnt[name] = 0;
		}
	}

	string Find(string name)
	{
		while (name != um_Parents[name])
		{
			name = um_Parents[name];
		}

		return name;
		//if (name == um_Parents[name])
		//{
		//	return name;
		//}
		//else
		//{
		//	um_ChildCnt[name] = 0;
		//	um_Parents[name] = Find(um_Parents[name]);
		//}
	}

	int Union(const string& a, const string& b)
	{
		const string& ra = Find(a);
		const string& rb = Find(b);
		if (ra == rb)
		{
			return um_ChildCnt[ra]+1;
		}

		if (um_Depth[ra] == um_Depth[rb])
		{
			um_Parents[ra] = rb;
			++um_Depth[rb];
			um_ChildCnt[rb] += (um_ChildCnt[ra] + 1);
			return um_ChildCnt[rb] + 1;
		}

		if (um_Depth[ra] < um_Depth[rb])
		{
			um_Parents[ra] = rb;
			um_ChildCnt[rb] += (um_ChildCnt[ra] + 1);
			return um_ChildCnt[rb] + 1;
		}

		if (um_Depth[ra] > um_Depth[rb])
		{
			um_Parents[rb] = ra;
			um_ChildCnt[ra] += (um_ChildCnt[rb] + 1);
			return um_ChildCnt[ra] + 1;
		}

	}

};


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int tcnt, fcnt;

	string a, b;

	cin >> tcnt;


	int ret;
	for (int t = 0; t < tcnt; ++t)
	{
		UF uf;
		cin >> fcnt;
		for (int f = 0; f < fcnt; ++f)
		{
			cin >> a >> b;
			uf.Insert(a);
			uf.Insert(b);

			ret = uf.Union(a, b);

			printf("%d\n", ret);
		}

	}


	return 0;
}