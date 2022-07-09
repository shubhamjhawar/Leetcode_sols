class Solution {
public:
    int f(int index,int option,vector<vector<int>>& dp,vector<int>& prices){
        
        //Base case
        if(index == prices.size()){
            return 0;
        }
        
        
        if(dp[index][option] != -1){
            return dp[index][option];
        }
        
        if(option == 1){
            dp[index][option] = max(-prices[index] + f(index+1,0,dp,prices),f(index+1,1,dp,prices)); 
        }
        else{
            dp[index][option] = max(prices[index] + f(index+1,1,dp,prices),f(index+1,0,dp,prices));  
        }
        
        return dp[index][option];  
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(0,1,dp,prices);
    }
};