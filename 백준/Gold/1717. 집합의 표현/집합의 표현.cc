#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> parent;
vector<int> depth;

struct Data
{
	int check;
	int a;
	int b;
};

int find(int a)
{
	if (parent[a] == a)
		return a;
	else
		return parent[a] = find(parent[a]);
}

void Union(int a, int b)
{
	int roota = find(a);
	int rootb = find(b);

	if (roota == rootb)
		return;

	if (depth[roota] < depth[rootb])
		parent[roota] = rootb;
	else
		parent[rootb] = roota;

	if (depth[roota] == depth[rootb])
		++depth[roota];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    
	int n, m;
	cin >> n >> m;
	parent.resize(n + 1);
	depth.resize(n + 1);

	for (int i = 0; i <= n; ++i)
	{
		parent[i] = i;
		depth[i] = 0;
	}
	
	vector<Data> data;
	for (int i = 0; i < m; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		data.push_back({ x, y, z });
	}

	for (size_t i = 0; i < data.size(); ++i)
	{
		if (data[i].check == 0)
		{
			Union(data[i].a, data[i].b);
		}
		else
		{
			if (find(data[i].a) != find(data[i].b))
				printf("NO\n");
			else
				printf("YES\n");
		}
	}

	return 0;
}