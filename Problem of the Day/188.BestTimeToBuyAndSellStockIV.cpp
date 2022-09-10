class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        
		// 0 days or 0 transactions
        if(n==0 || k==0)
            return 0;
        
        int i,j,mxp;
        int dp[k+1][n];
        
        for(i=0;i<=k;i++)
        {
            mxp=INT_MIN;
            for(j=0;j<n;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else
                {
					mxp=max(mxp,dp[i-1][j-1]-prices[j-1]);
                    dp[i][j]=max(dp[i][j-1],mxp+prices[j]);
                }
            }
        }
        
        return dp[k][n-1];
    }
};