
 Method 1 Recursion
class Solution {
public
    int solve(int index, int prev_index, vectorint &nums)
    {
        if(index == nums.size()) return 0;
        
         Not Take
        int len = 0 + solve(index+1, prev_index, nums);
            
         Take    
        if(prev_index == -1  nums[index]  nums[prev_index]) 
            len = max(len, 1+solve(index+1, index, nums));
            
        
        return len;
    }
    
    int lengthOfLIS(vectorint& nums) {
        return solve(0, -1, nums);
    }
};



 Method 2 Memoization
class Solution {
public
    int solve(int index, int prev_index, vectorint &nums,vectorvectorint& dp)
    {
        if(index == nums.size()) return 0;
        
        if(dp[index][prev_index+1] != -1)
            return dp[index][prev_index+1];
        
         Not Take
        int len = 0 + solve(index+1, prev_index, nums, dp);
            
         Take    
        if(prev_index == -1  nums[index]  nums[prev_index]) 
            len = max(len, 1+solve(index+1, index, nums, dp));
            
        
        return dp[index][prev_index+1] = len;
    }
    
    int lengthOfLIS(vectorint& nums) {
        int n = nums.size();
        
        vectorvectorint dp(n, vectorint (n+1, -1)); n+1,bcz we are shifting 1 prev_index 
        
        return solve(0, -1, nums, dp);
    }
};


 Method 3 Tabulation DP
class Solution {
public
    int lengthOfLIS(vectorint& nums) {
        int n = nums.size();
        vectorvectorint dp(n+1, vectorint (n+1, 0));
        
        for(int index = n-1; index = 0; index--)
        {
            for(int prev_index = index-1; prev_index = -1; prev_index--)
            {
                 Not Take
                int len = 0 + dp[index + 1][prev_index + 1];

                 Take    
                if(prev_index == -1  nums[index]  nums[prev_index]) 
                    len = max(len, 1 + dp[index + 1][index + 1]);


                dp[index][prev_index+1] = len;             
            }
        }
        
        
        return dp[0][-1+1];
    }
};