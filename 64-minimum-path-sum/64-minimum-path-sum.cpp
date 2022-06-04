class Solution {
public:
    int helper(int m ,int n ,vector<vector<int>>& cost,vector<vector<int>>& dp){
        
//         //Base case when index goes out of bound
//         if(i == 0 && j == 0){
//             return grid[0][0];        
//          }
        
//         //Base case when index goes out of bound
//         if( i < 0 || j < 0){
//             return 1e9;
//         }
      
//         if(dp[i][j] != -1){
//          return dp[i][j]; 
//         }
        
//         //Base case 
//         int up   = grid[i][j] +  helper(i-1,j,grid,dp);
//         int left = grid[i][j] + helper(i,j-1,grid,dp);
        
        
//         return dp[i][j] = min(up,left);   
        dp[0][0] = cost[0][0];
        //written the base case
        int left, up ;    
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 and j == 0){
                    dp[0%2][0] = cost[0][0] ;
                }
                else{
                    left = INT_MAX,up = INT_MAX;
                    if(i > 0){
                        up = dp[(i-1)%2][j] + cost[i][j];
                    }
                    if(j > 0){
                        left = dp[i%2][j-1] + cost[i][j];
                    }
                    
                    dp[i%2][j] = min(up,left);
                }
               
            }
        }
        return dp[(m-1)%2][n-1];
       
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(2,vector<int>(n,-1));
        return helper(m,n,grid,dp);
    }
};