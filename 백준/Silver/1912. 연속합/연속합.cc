#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define NINF -10000001

int main()
{
	int n;
	cin >> n;
	vector<int> nums;
	int maxnum = NINF;

	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
		maxnum = max(maxnum, tmp);
	}

	if (0 >= maxnum)
	{
		cout << maxnum;
		return 0;
	}

	int maxsum = 0;
	for (int right = 0; right < n; ++right)
	{

		if (0 > nums[right])
		{
			continue;
		}
		else
		{
			int tsum = nums[right];
			maxsum = max(maxsum, tsum);
			for (int left = right + 1; left < n; ++left)
			{
				if (0 >= (tsum + nums[left]))
				{
					right = left;
					break;
				}
				else
				{
					tsum = tsum + nums[left];
					maxsum = max(maxsum, tsum);
				}
			}
		}

	}

	cout << maxsum;

	return 0;
}