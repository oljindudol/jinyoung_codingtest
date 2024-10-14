class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int sz = nums.size();
        
        int left = 0;
        int right = sz-1;
        
        int minval = nums[0];
        int cur = (left+right) /2;
        
        
        if(nums[0] > nums[sz-1])
        {
                    //피봇구하기
            while(left <= right)
            {
                int mid = (left + right)/2;
                if(minval > nums[mid])
                {
                    minval = nums[mid];
                    cur = mid;
                    right = mid;
                }
                else
                {
                    left = mid+1;
                }
            }
        }
        else
        {
            cur = 0;
        }
        
        

        
        int pivot = cur;
        
        
        // 값 찾기
        cout << "pivot:"<<pivot <<endl;
        
        if(nums[sz-1] >= target )
        {
            left = pivot;
            right = sz-1;
        }
        else
        {
            left = 0;
            right = pivot-1;
        }
        cur = -1;
        
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(target == nums[mid])
            {
                cur = mid;
                break;
            }
            if(target < nums[mid])
            {
                cout<<"too big val:"<<nums[mid]<<" idx: "<<mid<<endl;
                right = mid-1;
            }
            else
            {
                cout<<"too small val:"<<nums[mid]<<"idx: "<<mid<<endl;
                left = mid+1;
            }
        }
        
        
        
        return cur;
    }
};