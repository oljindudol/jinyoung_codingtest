class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> um;
        for(int i =0 ; i<jewels.size();++i)
        {
           um.insert({jewels[i],0});
        }

        for(int i = 0 ; i<stones.size();++i)
        {
            auto f = um.find(stones[i]);
            if( um.end() != f)
            {
                ++((*f).second);
            }
        }
        int sum=0;
        for(const auto& c : um)
        {
            sum += c.second;
        }
        return sum;
    }
};