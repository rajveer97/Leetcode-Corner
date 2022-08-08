 // TLE
class Solution {
public:
    int solve(vector<int>&nums, int target)
    {
        if(target < 0) return 0;
        if(target == 0) return 1;
        
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            ans += solve(nums, target-nums[i]);
        }
        
        return ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums, target);
    }
};


//-------------------------------------------------------

// Method 2: Memoization
class Solution {
public:
    int solve(vector<int>&nums, int target, vector<int> &dp)
    {
        if(target < 0) return 0;
        if(target == 0) return 1;
        
        if(dp[target] != -1)
            return dp[target];
        
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            ans += solve(nums, target-nums[i], dp);
        }
        
        dp[target] = ans;
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return solve(nums, target, dp);
    }
};


//-----------------------------------------------------------
// Method 3: Tabulation DP
class Solution {
public:
    int solve(vector<int>&nums, int target)
    {
        vector<long long int> dp(target+1, 0);
        
        dp[0] = 1;
        
        // Traversing tar from 1 to target
        for(int i = 1; i <= target; i++)
        {
            // Traversing on the nums vector
            for(int j=0; j<nums.size(); j++)
            {
                if(i - nums[j] >= 0)
                    dp[i] = dp[i] + (int)dp[i - nums[j]];
            }
        }
        
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums, target);
    }
};
