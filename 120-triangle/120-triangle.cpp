class Solution {
public:
    int helper(vector<vector<int>>& triangle,vector<vector<int>>& dp,int n){
        int i , j;
        
        for(j = 0 ; j < n ; j++){
            dp[(n-1)%2][j] = triangle[n-1][j];
        }
        
        for(i = n-2 ; i >= 0 ;i--){
            for(j = 0 ; j < triangle[i].size() ; j++){
               dp[i%2][j] = triangle[i][j] + min(dp[(i+1)%2][j] ,dp[(i+1)%2][j+1]); 
            } 
        }
        
        return dp[0%2][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(2,vector<int>(n,-1));
        return helper(triangle,dp,n);
    }
};