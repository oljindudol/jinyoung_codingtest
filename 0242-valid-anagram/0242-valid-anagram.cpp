class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> s1;
        unordered_map<char,int> s2;
        
        
        for(int i = 0; i < s.size() ; ++i)
        {
            ++s1[s[i]];
        }
        
        for(int i = 0; i < t.size() ; ++i)
        {
            ++s2[t[i]];
        }
        
        if(s1.size() != s2.size())
            return false;
        
        for(auto& c : s1)
        {
            if(c.second != s2[c.first])
                return false;
        }
        
        return true;
    }
};