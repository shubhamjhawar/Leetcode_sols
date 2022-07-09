class Solution {
public:
//      int f(int n,int option,int cap,vector<vector<vector<int>>>& dp,vector<int>& prices){
        
//          for(int i = n-1; i >= 0 ; i--){
//              for(int j = 0 ; j <= 1 ; j++){
//                  for(int cap = 1 ; cap <= 2; cap++){
//                      if(j == 1)
//                          dp[i][j][cap] = max(-prices[i] + dp[i+1][0][cap],dp[i+1][1][cap]);
//                      else
//                          dp[i][j][cap] = max( prices[i] + dp[i+1][1][cap-1],dp[i+1][0][cap]);  
//                  }
//              } 
//          }
        
        
//         return dp[0][1][cap];

//     }
int f(int index,int option,int cap,vector<vector<vector<int>>>& dp,vector<int>& prices){
        
        //Base case
         if(cap == 0 || index == prices.size()){
            return 0;
        }

        if(dp[index][option][cap] != -1){
            return dp[index][option][cap];
        }
        
        int profit ;
        if(option == 0){
            profit = max(-prices[index] + f(index+1,1,cap,dp,prices),f(index+1,0,cap,dp,prices)); 
        }
        else{
            profit = max(prices[index] + f(index+1,0,cap-1,dp,prices),f(index+1,1,cap,dp,prices));  
        }
        
        return dp[index][option][cap] = profit;  
}
  
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,0,2,dp,prices);
    }
};
                                      
