class Solution {
public:
void fibHelper(int n,vector<int>& dp){

    dp[0%2] = 0;
    dp[1%2] = 1;
    
    for(int i = 2 ; i <= n ; i++){
        dp[i%2] = dp[(i-1)%2] + dp[(i-2)%2];
    }
    
    return;
}
int fib(int n) {
        
      vector<int>dp(2,0);
      fibHelper(n,dp);
     
      return dp[n%2];
}
};