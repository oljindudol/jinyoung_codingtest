class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int prod1 = 1;
        int prod2 = 1;
        vector<int> res;
        res.resize(len);

        for (int i = 0; i < len; i++)
        {
            res[i] = 1;
        }

        for (int i = 0; i < len; i++)
        {
            res[i] *= prod1;
            res[len - i - 1] *= prod2;
            prod1 *= nums[i];
            prod2 *= nums[len - i - 1];
        }

        return res;
    }

};