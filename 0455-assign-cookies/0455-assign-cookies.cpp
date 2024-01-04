class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ret =0;
        
        while(0 != g.size() && 0 !=s.size())
        {
            //충족하는경우
            if(g.back() <= s.back())
            {
                ++ret;
                g.pop_back();
                s.pop_back();
            }
            else
            {
                g.pop_back();
            }
        }
        
        return ret;
    }
};