class Solution {
public:
   int f(vector<vector<int>>& dp,string& s,string& t,int n ,int m){
       
       static int  MOD = 1e9 + 7;
       for(int i = 0 ; i <= n ; i++){
           dp[i][0] = 1;
       }
       
       for(int i = 1 ; i <= n ; i++){
           for(int j = 1 ; j <= m ; j++){
               if(s[i-1] == t[j-1]){
                   dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
               }
               else{
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       
       return dp[n][m]; 
   }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        return f(dp,s,t,n,m);
    }
};