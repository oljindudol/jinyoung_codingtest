class Solution {
public:
    static bool cmp (int& _a,int& _b)
    {
        string a = to_string(_a);
        string b = to_string(_b);
        
        
        return a+b > b+a;
    }
    
    
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),cmp);
        
        //0,0예외처리
        auto iter = nums.begin();
        while(nums.end() != iter && 0 == (*iter) )
        {
            iter = nums.erase(iter);
        }
        if(0 == nums.size())
            nums.push_back(0);
        
        string ret="" ; 
        for(auto& i : nums)
        {
            ret += to_string(i);
        }
        return ret;
    }
};