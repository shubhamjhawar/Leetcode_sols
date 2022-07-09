class Solution {
public:
    int f(int n,int option,vector<vector<int>>& dp,vector<int>& prices){
         dp[n][0] = 0,dp[n][1] = 0;
        
         for(int i = n-1; i >= 0 ; i--){
               dp[i][1] = max(-prices[i] + dp[i+1][0],dp[i+1][1]);
               dp[i][0] = max( prices[i] + dp[i+1][1],dp[i+1][0]);
         }
        
        
        return dp[0][1];

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return f(n,1,dp,prices);
    }
};