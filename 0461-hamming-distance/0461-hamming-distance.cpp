class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret = 0 ;
        bitset<32> xb(x), yb(y);
        
        for(int i = 0 ; i <32; ++i )
        {
            if( xb[i] != yb[i])
                ++ret;
        }
        
        return ret;
    }
};