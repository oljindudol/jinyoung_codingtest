class Solution {
public:
    int mySqrt(int x) {
        long long target = x;
        int left = 0;
        int right =x;
        
        while(left <= right)
        {
            long long mid = (left+right)/2;
            long long res = mid*mid;
            
            if(target == res)
            {
                return mid;
            }
            else if(target > res)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        
        return right;
    }
};