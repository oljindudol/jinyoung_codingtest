class Solution {
public:
    struct cmp {
        bool operator() (pair<int,int> _pa , pair<int,int> _pb)
        {
            if(_pa.first == _pb.first)
            {
                return _pa.second > _pb.second;
            }
            return _pa.first < _pb.first;
        }
    };

    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        int sz = nums.size();
        int cnt = sz-k+1;
        //val,idx
        priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;
        
        for(int i = 0 ; i < k ; ++i)
        {
            pq.push({nums[i],i});
        }

        ret.push_back(pq.top().first);
        for(int i = 1 ; i< cnt; ++i)
        {
            pq.push({nums[i+k-1],i+k-1});
            while(i > pq.top().second)
            {
                pq.pop();
            }
            ret.push_back(pq.top().first);
        }
        
        return ret;
    }
};