#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int trap(vector<int>& height) {
    int ret = 0;

    while (0 == height[0])
    {
        height.erase(height.begin());
    }
    while (0 == height[(height.size()-1)])
    {
        height.erase(height.begin()+ (height.size()-1));
    }
    if (1 >= height.size())
    {
        return 0;
    }

    for (int i = 0; i < height.size()-1;)
    {
        bool next = false;
        int nexteog=0;
        for (int j = (i + 1); j < height.size(); ++j)
        {
            if (height[i] <= height[j])
            {
                if (i + 1 == j)
                {
                    i = j;
                    bool next = true;
                    break;
                }
                else
            }
        }
        if (0 != nexteog)
        {
            for()
        }
    }

    return ret;

}


int main()
{
    vector<int> tc = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    trap(tc);
    return 0;
}