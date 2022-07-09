class Solution {
public:
     int f(int n,int option,vector<vector<int>>& dp,vector<int>& prices){
         dp[n%3][0] = 0,dp[n%3][1] = 0;
        
         for(int i = n-1; i >= 0 ; i--){
               dp[i%3][1] = max(-prices[i] + dp[(i+1)%3][0],dp[(i+1)%3][1]);
               if(i+1 == n){
                  dp[i%3][0] = max( prices[i] + dp[(i+1)%3][1],dp[(i+1)%3][0]); 
               }
               else{
                   dp[i%3][0] = max( prices[i] + dp[(i+2)%3][1],dp[(i+1)%3][0]);
               }
                   
         }
        
        
        return dp[0%3][1];

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(3,vector<int>(2,0));
        return f(n,1,dp,prices);
    }
};