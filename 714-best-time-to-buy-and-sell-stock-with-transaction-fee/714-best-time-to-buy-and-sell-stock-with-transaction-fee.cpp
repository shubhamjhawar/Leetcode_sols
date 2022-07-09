class Solution {
public:
     int f(int n,int option,vector<vector<int>>& dp,vector<int>& prices,int fee){
         dp[n%2][0] = 0,dp[n%2][1] = 0;
        
         for(int i = n-1; i >= 0 ; i--){
               dp[i%2][1] = max(-prices[i] + dp[(i+1)%2][0],dp[(i+1)%2][1]);
               dp[i%2][0] = max( prices[i] + dp[(i+1)%2][1] - fee,dp[(i+1)%2][0]);
         }
        
        
        return dp[0%2][1];

    }
  
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(2,vector<int>(2,-1));
        return f(n,1,dp,prices,fee);
    }
};