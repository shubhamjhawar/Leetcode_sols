class Solution {
public:
    int f(vector<vector<int>>& matrix,vector<vector<int>>& dp){
       int n = matrix.size();
       for(int k = 0 ;k < n ; k++){
           dp[0%2][k] = matrix[0%2][k];
       }
        
       for(int i = 1 ; i < n ;i++){
           for(int j = 0 ; j < n ; j++){
               int up = 1e9,ld = 1e9 ,rd = 1e9;
                up = dp[(i-1)%2][j] + matrix[i][j];
               if(j-1 >= 0){
                   ld = dp[(i-1)%2][j-1] + matrix[i][j];
               }
               if(j+1 < n){
                   rd = dp[(i-1)%2][j+1] + matrix[i][j];
               }
               
               dp[i%2][j] = min(up,min(ld,rd));
           }
       }
       int min_elt = INT_MAX;
       for(int i = 0 ; i < n ; i++){
           min_elt = min(min_elt,dp[(n-1)%2][i]);
       }
       return min_elt;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(2,vector<int>(n,100005));
        return f(matrix,dp);

    }
};