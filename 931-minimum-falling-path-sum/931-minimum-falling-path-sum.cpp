class Solution {
public:
 int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int n = matrix.size();
        //Base case
        if(j < 0 || j >= n)
            return 1e9;
        if(i == 0)  
           return matrix[0][j];
        
        if(dp[i][j] != 100005){
            return dp[i][j];
        }
        
        //Recursive case
        int up = f(i-1,j,matrix,dp) + matrix[i][j];
        int ld = f(i-1,j-1,matrix,dp)  + matrix[i][j];
        int rd = f(i-1,j+1,matrix,dp)  + matrix[i][j];
        
        return dp[i][j] =  min(up,min(ld,rd));
        
    }
 int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    //int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(n,100005));
    
    int maxi = INT_MAX;
    
    for(int j=0; j<n;j++){
        int ans = f(n-1,j,matrix,dp);
        maxi = min(maxi,ans);
    }
    
    return maxi;
    }
};