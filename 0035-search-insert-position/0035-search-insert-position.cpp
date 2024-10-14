class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int sz = nums.size();
        
        int left = 0;
        int right =sz-1;
        int cur = (left+right)/2;
        
        while(left <= right)
        {
            int mid = (left+right) /2;
            cout <<"left:"<<left <<" right:"<<right;
            if(target ==nums[mid] )
            {
                cur = mid;
                left =cur;
                break;
            }
            else if( target > nums[mid])
            {
                left = mid+1;
                cur = mid;
                cout<<" too small idx,val:"<<mid<< ","<< nums[mid] <<endl;
            }
            else
            {
                right = mid-1;
                cur =mid;
                cout<<" too big idx,val:"<<mid<< ","<<nums[mid] <<endl;
            }
        }
        
        return left;
        
    }
};