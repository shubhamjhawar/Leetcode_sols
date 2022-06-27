class Solution {
public:
    int helper(int i ,int j ,vector<vector<int>>&dp,vector<vector<int>>& grid){
        
        if(i >= 0 && j >= 0 &&  grid[i][j] == 1) return 0;
        if(i == 0 and j == 0){
            return 1;        
         }
        
        if( i < 0 or j < 0){
            return 0;
        }
        
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int up = helper(i-1,j,dp,grid);
        int left = helper(i,j-1,dp,grid);
        
        return dp[i][j] =  up + left;   
        
    }
    int f(int i ,int j ,vector<vector<int>>&dp,vector<vector<int>>& grid){
        
         int m = grid.size();
         int n = grid[0].size();
         int up,left;
        
        for(int i = 0 ; i < m ; i++ ){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    if(i == 0 && j == 0){
                        dp[i][j] = 1;
                    }
                    else{
                        up = 0,left = 0;
                        if(i > 0){
                            up = dp[i-1][j];
                        }
                        else{
                            left = dp[i][j-1];
                        }
                    }
                }
            }
        }
        
        return dp[m-1][n-1];
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int m = obstacleGrid.size();
       int n = obstacleGrid[0].size();
       vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp,obstacleGrid);
    } 
    
};