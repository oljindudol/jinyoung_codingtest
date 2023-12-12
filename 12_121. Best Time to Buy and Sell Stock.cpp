class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (1 == prices.size())
            return 0;
        int pricemin = prices[0];
        int profitmax = 0;

        for (int i = 0; i < prices.size(); ++i)
        {

            if (pricemin > prices[i])
            {
                pricemin = prices[i];
                continue;
            }

            if (profitmax < prices[i] - pricemin)
                profitmax = prices[i] - pricemin;
        }
        return profitmax;
    }
};