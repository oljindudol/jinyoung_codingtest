class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        vector<int> ret;
        int sz = nums.size();
        
        for(int i = 0 ; i<sz ; ++i )
        {
            auto f = um.find(nums[i]);
            
            if(um.end() == f)
            {
                um.insert({nums[i],1});
            }
            else
            {
                ++((*f).second);
            }
            
        }
        vector<pair<int, int>> sortedvec(um.begin(), um.end());
        sort(sortedvec.begin(), sortedvec.end(), cmp);
        
        for(int i = 0 ; i<k;++i)
        {
            ret.push_back(sortedvec[i].first);
            
        }
        
        return ret;
    }
};