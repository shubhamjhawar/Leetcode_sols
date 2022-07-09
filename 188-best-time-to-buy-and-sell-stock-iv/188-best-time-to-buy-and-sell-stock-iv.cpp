class Solution {
public:
int f(int n,int k,vector<vector<vector<int>>>& dp,vector<int>& prices){
        
         for(int i = n-1; i >= 0 ; i--){
             for(int j = 0 ; j <= 1 ; j++){
                 for(int cap = 1 ; cap <= k; cap++){
                     if(j == 0)
                         dp[i%2][j][cap] = max(-prices[i] + dp[(i+1)%2][1][cap],dp[(i+1)%2][0][cap]);
                     else
                         dp[i%2][j][cap] = max( prices[i] + dp[(i+1)%2][0][cap-1],dp[(i+1)%2][1][cap]);  
                 }
             } 
         }
        
        
        return dp[0%2][0][k];

}
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(2,vector<int>(k+1,0)));
        return f(n,k,dp,prices);
    }
};