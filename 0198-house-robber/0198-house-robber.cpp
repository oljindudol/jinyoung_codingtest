class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if(1 == sz)
        {
            return nums[0];
        }
        if(2 == sz)
        {
            return max(nums[0],nums[1]);
        }
        
        vector<int> memo;
        memo.resize(sz);
        memo[0] = nums[0];
        memo[1] = max(nums[0],nums[1]);
        
        for(int i = 2; i<sz; ++i)
        {
            memo[i] =max(memo[i-1] , (memo[i-2]+nums[i]) );
        }
        
        return memo[sz-1];
    }
};