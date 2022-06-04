class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp,int n){
        //Base case
        if(i == n-1){
            return triangle[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        //Recursive case
        int down = helper(i+1,j,triangle,dp,n) + triangle[i][j];
        int diag = helper(i+1,j+1,triangle,dp,n) + triangle[i][j];
        
        dp[i][j] = min(down,diag);
        return dp[i][j];
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(0,0,triangle,dp,n);
    }
};