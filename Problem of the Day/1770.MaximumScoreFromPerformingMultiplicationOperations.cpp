class Solution {
public:
    int mn = -1e5;
    int dp[1001][1001];


    int solve(vector<int>&nums,vector<int>&multipliers,int st,int en,int ind){
        if(ind == multipliers.size()){
            return 0;
        }

        if(dp[ind][st] != mn){
            return dp[ind][st];
        }     

        int n = nums.size();

        // solve
        int mul = multipliers[ind];
        int call1 = mul*nums[st] + solve(nums,multipliers,st+1,en,ind+1);
        int call2 = mul*nums[en] + solve(nums,multipliers,st,en-1,ind+1);

        return dp[ind][st] = max(call1,call2);    
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {  
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                dp[i][j] = mn;
            }
        }
        return solve(nums,multipliers,0,nums.size()-1,0);
    }
};

// Time Complexity : O(2 * m^2) -> in this question O( sizeof(multiplier vector)^2 ) 
// as thats the limiting constraint.
// Space Complexity : O(m^2)