class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        
        while(lo < hi)
        {
            int mid = lo + (hi-lo)/2;
            
            if(nums[mid] < nums[hi])
                // the mininum is in the left part
                hi = mid;
            else if(nums[mid] > nums[hi])
                // the mininum is in the right part
                lo = mid + 1;
            
                           
        }
        
        return nums[lo];
    }
};
