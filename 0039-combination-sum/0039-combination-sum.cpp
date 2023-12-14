class Solution {
public:
    
    void push_data(vector<int> _v ,int sum  , int before , int target 
                   ,vector<int>& candidates,vector<vector<int>>& _out)
    {
        if( sum > target)
        {
            return;
        }
        else if( sum == target)
        {
            _out.push_back(_v);
            return;
        }
        
        for(int i = before; i<candidates.size(); ++i)
        {
            vector<int> tmp = _v;
            tmp.push_back(candidates[i]);
            
            push_data(tmp,sum+candidates[i] ,i, target, candidates ,_out);
        }
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> tmp;
        
        push_data(tmp, 0  ,0, target, candidates ,ret);
        
        return ret;
    }
};