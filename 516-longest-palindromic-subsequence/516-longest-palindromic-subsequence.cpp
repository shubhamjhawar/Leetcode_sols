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

     return dp[n1][n2];
         
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s1.begin(),s1.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return f(n,n,dp,s,s1);
        
    }
};