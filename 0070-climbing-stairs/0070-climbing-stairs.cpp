class Solution {
public:
//  int ret;
//     void recur(int n)
//     {
//         if(0==n)
//         {
//             ++ret;
//             return;
//         }
        
//         if(0 <= (n-1))
//         {
//             recur(n-1);
//         }
//         if(0 <= (n-2))
//         {
//             recur(n-2);
//         }
//     }
    
    int climbStairs(int n) {
        //sol1
        // recur(n);
        
        //sol2
        // if( 0 >= n)
        // {
        //     return 0;
        // }
        // if( 1 == n)
        // {
        //     return 1;
        // }
        // if( 2 == n)
        // {
        //     return 2;
        // }
        // return climbStairs(n-1) + climbStairs(n-2);
        
        //sol3
        if(1 == n)
            return 1;
        if(2 == n)
            return 2;
        
        vector<int> memo;
        memo.resize(n);
        
        memo[0]=1;
        memo[1]=2;
        
        for(int i=2;i<n;++i)
        {
            memo[i]=memo[i-1] + memo[i-2];
        }
        
        return memo[n-1];
    }
};