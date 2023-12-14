class Solution {
public: 
    
    void swap(int& _a,int& _b)
    {
        int tmp = _a;
        _a =  _b;
        _b = tmp;   
    }
    
    void pushdata(vector<int> _v , int depth , 
                  vector<vector<int>>& _out )
    {
        if(depth == _v.size())
        {
            _out.push_back(_v);
            return;
        }
        
        for(int i =depth ; i< _v.size(); ++i)
        {
            swap(_v[depth], _v[i]);
            pushdata(_v, depth + 1, _out);
            swap(_v[depth], _v[i]);
        }
        
    }
    
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        
        int sz = nums.size();
        
        if(0==sz)
            return ret;
        
        vector<int> tmp;
        pushdata(nums  , 0  , ret);
        return ret;
    }
};