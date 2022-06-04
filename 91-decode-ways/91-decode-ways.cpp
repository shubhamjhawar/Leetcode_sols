class Solution {
public:
    int helper(string& s,int index,vector<int>& dp){
        int n = s.size();
        //Base Case
        if(index == n) return 1;
        if(s[index]=='0')return 0;
        if(index == n-1) return 1;
        
        
        int lh = 0;
        int rh = 0;
        
        if(dp[index] != -1){
            return dp[index];
        }
        
        //Recursive case
        if(s[index] != '0'){
            lh = helper(s,index+1,dp);
        }
        
        if(index + 1 < n && s[index] != '0' && (s[index] == '1' || s[index] == '2' && s[index+1] <= '6' )){
            rh = helper(s,index+2,dp);
        }
        
        
        return dp[index] = (lh + rh);
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
     
        return helper(s,0,dp);
        
    }
};