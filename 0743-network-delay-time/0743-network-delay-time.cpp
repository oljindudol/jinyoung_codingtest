class Solution {

#define inf 100001
public:
    
    
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
    }
};