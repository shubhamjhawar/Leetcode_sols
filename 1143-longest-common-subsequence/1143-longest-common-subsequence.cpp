class Solution {
public:
    int f(int n1,int n2,vector<vector<int>>& dp,string& text1, string& text2){
        
        //Base case
      
       for(int j = 0 ; j <= n2 ; j++){
           dp[0][j] = 0;
       }
        
      for(int i = 1 ; i <= n1 ; i++){
          dp[i][0] = 0;
          for(int j = 1 ; j <= n2 ; j++){
              if(text1[i-1] == text2[j-1]){
                  dp[i][j] = 1 + dp[(i-1)][j-1];
              }
              else{
                  dp[i][j] = max(dp[i][j-1],dp[(i-1)][j]);
              }
          }
      }
//       for(int i = 0 ; i <= n1 ; i++){
//             for(int j = 0 ; j <= n2 ; j++){
//                 cout << dp[i][j] << " ";
//             }
//             cout << endl;
//         }
         
     return dp[n1][n2];
         
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        
        return f(n1,n2,dp,text1,text2);
    }
};