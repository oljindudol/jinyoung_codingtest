class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        auto sz = numbers.size();
        //값,vec
        unordered_map<int,vector<int>> um;
        
        for(int i = 0 ; i< sz ; ++i)
        {
            auto iter = um.find(numbers[i]);
            
            if(um.end() == iter)
            {
                vector<int> t;
                t.push_back(i);
                um.insert({numbers[i],t});
            }
            else
            {
                (*iter).second.push_back(i);
            }
        }
        
        for(int i = 0 ; i< sz ; ++i)
        {
            auto iter = um.find(target-numbers[i]);
            if(um.end() != iter)
            {
                auto v1 = um[numbers[i]];
                auto v2 = um[target-numbers[i]];
                
                if( numbers[i] != target-numbers[i])
                {
                    ret.push_back(v1[0]+1);
                    ret.push_back(v2[0]+1);
                    break;
                }
                if( 1 < v1.size())
                {
                    ret.push_back(v1[0]+1);
                    ret.push_back(v1[1]+1);
                    break;
                }
                
            }

        }
        return ret;
    }
};