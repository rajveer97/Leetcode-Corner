
 //Method 1 Recursion
class Solution {
public
    const int MOD = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        return helper(n, k, target);
    }
    int helper(int n, int k, int target) {
        if (target == 0) return n == 0;
        if (n == 0  target  0) return 0;
        
        int ways = 0;
        for (int i=1; i=k; ++i) {
            ways = (ways + helper(n-1, k, target-i)) % MOD;
        }
        return ways % MOD;
    }
};



 // Method 2 Top-down DP Brute-force + memoization
class Solution {
public
    const int MOD = 1e9+7;
    vectorvectorint memo;
    int numRollsToTarget(int n, int k, int target) {
        memo = vectorvectorint(n+1, vectorint(target+1, -1));
        return helper(n, k, target);
    }
    int helper(int n, int k, int target) {
        if (target == 0) return n == 0;
        if (n == 0  target  0) return 0;
        if (memo[n][target] != -1) return memo[n][target];
        
        int ways = 0;
        for (int i=1; i=k; ++i) {
            ways = (ways + helper(n-1, k, target-i)) % MOD;
        }
        return memo[n][target] = ways % MOD;
    }
};



 // Method 3: DP Tabulation 
class Solution {
public
    const int MOD = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
         //dp[i][t] number of possible ways to roll i dices so the sum of the face-up numbers equals t.
        vectorvectorint dp = vectorvectorint(n+1, vectorint(target+1, 0));

        dp[0][0] = 1;  //only 1 ways to roll zero dice with sum = 0

        for(int i=1; i=n; ++i)
        {
            for(int t=1; t=target; ++t)
            {
                for(int j=1; j=k; ++j)
                {
                    if(j=t)
                    {
                        dp[i][t] = (dp[i][t] + dp[i-1][t-j]) % MOD;
                    }
                }
                
            }
        }

        return dp[n][target];
    }
};

