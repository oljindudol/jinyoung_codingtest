class Solution {
public:

    
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto sz = nums.size();
        int szm = sz - 2;
        for(int i = 0 ; i< szm; i+= 2)
        {
            if(nums[i] != nums[i+1])
                return nums[i];
        }
        return nums[sz-1];
    }
};