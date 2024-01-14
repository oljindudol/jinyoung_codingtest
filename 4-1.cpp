#include "check.h"
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_set>
#include <set>
using namespace std;


#define inf 100001

int networkDelayTime(vector<vector<int>>& times, int n, int k) {

    vector<vector<int>> cost;
    for (int i = 0; i < n; ++i)
    {
        vector<int> tmp;
        tmp.resize(n, inf);
        cost.push_back(tmp);
        cost[i][i] = 0;
    }

    vector<bool> visited;
    visited.resize(n, false);

    for (auto& t : times)
    {
        cost[t[0] - 1][t[1] - 1] = t[2];
    }


    int start = k - 1;
    visited[start] = true;
    for (int i = 0; i < n; ++i)
    {
        int minval = inf;
        int minidx = -1;

        //최소비용 길 알아내기
        for (int j = 0; j < n; ++j)
        {
            if (false == visited[j])
            {
                int& c = cost[start][j];
                if (minval > c)
                {
                    minval = c;
                    minidx = j;
                }
            }
        }

        if (-1 != minidx)
        {
            visited[minidx] = true;
        }
        else
        {
            break;
        }

        //최소비용 길 알아내기
        for (int j = 0; j < n; ++j)
        {
            if (inf == cost[minidx][j]
                || true ==visited[j])
            {
                continue;
            }
            if (cost[start][j] > (minval + cost[minidx][j]))
            {
                cost[start][j] = minval + cost[minidx][j];
            }
        }
    }
    
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        int c = cost[start][i];

        max = max < c ? c : max;

    }

    if (inf == max)
    {
        return -1;
    }

    return max;

    //int acc = 0;
    //while (true)
    //{
    //    int minval = 101;
    //    int minidx = -1;

    //    //코스트를 갱신
    //    //가장 작은 경로를 탐색
    //    for (int i = 0; i < n; ++i)
    //    {
    //        int& c = cost[from][i];
    //        if (-1 != c)
    //        {
    //            int& c2 = cost[k - 1][i];
    //            if (-1 == c2 ||
    //                ((-1 != c2) && (c2 > c + acc)))
    //            {
    //                c2 = c + acc;
    //            }

    //            //코스트 작은경로 갱신
    //            if (minval > c)
    //            {
    //                minval = c;
    //                minidx = i;
    //            }
    //        }
    //    }

    //    if (-1 != minidx && false == visited[minidx])
    //    {
    //        from = minidx;
    //        acc += minval;
    //        visited[minidx] = true;
    //        continue;
    //    }

    //    //전부 방문했는지 검사
    //    for (int i = 0; i < n; ++i)
    //    {
    //        if (false == visited[i])
    //        {
    //            from = i;
    //            visited[i] = true;
    //            acc = 0;
    //            continue;
    //        }
    //    }
    //    //전부방문했다면 break
    //    break;
    //}

    //auto min = min_element(cost[k - 1].begin(), cost[k - 1].end());
    //return *min;
}

int main()
{

    vector<vector<int>> input;
    //vector<char> vc1{ '1', '1', '1', '1', '0' };
    //vector<char> vc2{ '1', '1', '0', '1', '0' };
    //vector<char> vc3{ '1', '1', '0', '0', '0' };
    //vector<char> vc4{ '0', '0', '0', '0', '0' };

    vector<int> vc1{ 2,1,1, };
    vector<int> vc2{ 2,3,1, };
    vector<int> vc3{ 3,4,1, };

    input.push_back(vc1);
    input.push_back(vc2);
    input.push_back(vc3);

    networkDelayTime(input,4,2);
    return 0;
}