class Solution {
public:
    struct cmp
    {
      bool operator()(vector<int> _a, vector<int> _b)
      {
          if(_a[0] == _b[0])
          {
              return _a[1] > _b[1];
          }
          return _a[0] < _b[0];
      }
    };
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
        vector<vector<int>> ret;
        
        for(int i = 0 ; i < people.size(); ++i)
        {
            pq.push(people[i]);
        }
        
        ret.push_back(pq.top());
        pq.pop();
        
        while(0 != pq.size())
        {
            auto iter = ret.begin();
            auto v = pq.top();
            pq.pop();
            
            ret.insert(iter+v[1],v);
        }
        
        return ret;
        
    }
};