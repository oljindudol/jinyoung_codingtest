class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz= s.size();
        if(0==sz)
        {
            return 0;
        }
        if(1==sz)
        {
            return 1;
        }
        
        unordered_set<char> us;
        int max = 1; 
        
        for(int i=0;i<sz-1; ++i)
        {
            us.insert(s[i]);
            for(int j=i+1 ; j<sz; ++j)
            {
                auto f = us.find(s[j]);
                if(us.end() == f)
                {
                    us.insert(s[j]);                    
                }
                else
                {

                    break;
                }
            }
            if(max< us.size())
                max = us.size();
            us.clear();
            if(max>(sz-i-1))
                break;
        }
        
        return max;
    }
};