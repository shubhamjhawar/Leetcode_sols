class Solution {
public:
    int lcs(string& s1,string& s2,int n){
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int i,j;
        for(i = 0 ; i <= n ; i++) dp[i][0] = 0;
        for(j = 0 ; j <= n ; j++) dp[0][j] = 0;
        
        for(i  = 1 ; i <= n ; i++){
            
            for(j = 1;j <= n ; j++){
                
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][n];
    }
    int minInsertions(string s) {
        string s1 = s;
        int n = s.size();
        reverse(s1.begin(),s1.end());
        int len = lcs(s,s1,n);
        return s.size() - len;
    }
};