class Solution {
public:
   int f(vector<vector<int>>& dp,string& s,string& t,int i ,int j){
           
       //Base case
       if(j < 0) return 1;
       if(i < 0) return 0;
       
       if(dp[i][j] != -1){
           return dp[i][j];
       }
       
       int lh = 0,rh = 0;
      
       
       if(s[i] == t[j]){
           lh = f(dp,s,t,i-1,j-1);
           rh = f(dp,s,t,i-1,j);
           dp[i][j] = lh + rh;
       }
       else{
           dp[i][j] = f(dp,s,t,i-1,j);
       }
     
       return dp[i][j];
   }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(dp,s,t,n-1,m-1);
    }
};