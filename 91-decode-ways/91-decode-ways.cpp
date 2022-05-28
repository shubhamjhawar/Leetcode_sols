class Solution {
public:
    int helper(string& s,int index,vector<int>& dp){
        int n = index;
        dp[n%2] = 1;
        dp[(n-1)%2] = s[n-1] == '0' ? 0 : 1;
        
      for(int i = n-2 ; i >= 0 ; i--){
         int temp = 0;
        //Recursive case
        if(s[i] != '0'){
            temp += dp[(i+1)%2];
        }
        
        if(s[i] == '1' || s[i] == '2' && s[i+1] <= '6' ){
            temp += dp[(i+2)%2];
        }
          
        dp[i%2] = temp;
        
      }
        
      return dp[0%2];
        
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(2);
     
        return helper(s,n,dp);
        
    }
};