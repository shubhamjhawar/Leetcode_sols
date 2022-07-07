// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int f(int i1,int i2,vector<vector<int>>& dp,string& text1, string& text2){
    
        
        for(int  j = 0 ; j <= i2 ; j++){
            dp[0][j] = 0;
        }
        
      int maxi = 0;
      for(int i = 1 ; i <= i1 ; i++){
            dp[i][0] = 0;
            for(int j = 1 ; j <= i2 ; j++){
                if(text1[i-1] == text2[j-1]){
                     dp[i][j] =  1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 0;
                }
               maxi = max(maxi,dp[i][j]);
            }
        }
 
  return maxi;

}
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        
        return f(n,m,dp,S1,S2);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends