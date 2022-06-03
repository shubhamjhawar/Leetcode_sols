class Solution {
public:
    int helper(int m ,int n ,vector<vector<int>>&dp){
        
      dp[0%2][0] = 1;
      int left ,up;
      for(int i = 0 ;i < m ; i++){
          for(int j = 0 ; j < n ; j++){
              if(i == 0 and j == 0 ) 
                  dp[0%2][0] = 1;
              else{
                  up = 0 ,left = 0;
                  if(i > 0)
                      up = dp[(i-1)%2][j];
                  if(j > 0){
                      left = dp[i%2][j-1];
                  }
                  
                  dp[i%2][j] = left + up;
              }
          }

      }
    return dp[(m-1)%2][(n-1)];
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(2,vector<int>(n,0));
        return helper(m,n,dp);
    }
};