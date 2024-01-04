class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>& p = prices;
        int sz = prices.size();
        int from = -1;
        int to = -1;
        int profitsum = 0;
        bool findmax =false;
        int cnt = sz-1;
        
        
        for(int i = 0; i<cnt; ++i)
        {
            //저점찾기
            if(false == findmax)
            {
                if(p[i] < p[i+1])
                {
                    from = i;
                    findmax = true;
                }
            }
            //고점찾기
            else
            {
                if(p[i] > p[i+1])
                {
                    to = i;
                    profitsum = profitsum + p[to]-p[from];
                    to = -1;
                    from = -1;
                    findmax = false;
                }
            }
        }
        
        if(-1 == from)
            return profitsum;
        if(-1 == to)
            profitsum = profitsum + p[cnt]-p[from];
        
        return profitsum;
    }
};