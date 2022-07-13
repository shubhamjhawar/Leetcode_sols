class Solution {
public:
    int helper(string& s,int n,vector<int>& dp){
       
        if(s[0] == '0') return 0;
        dp[n%2] = 1;
        if(s[n-1] != '0')
            dp[(n-1)%2] = 1;
        
        for(int i = n-2 ; i >= 0 ; i--){
            int cnt  = 0;
            if(s[i] != '0'){
                cnt += dp[(i+1)%2];
            }
            if(s[i] == '1' || (s[i] == '2' and s[i+1] <= '6')){
                cnt += dp[(i+2)%2];
            }
            
            dp[i%2] = cnt;
        }
        
        return dp[0%2];
    }
    int numDecodings(string s) {
        
        int n = s.size();
        vector<int> dp(2,0);
        return helper(s,n,dp);
        
    }
};