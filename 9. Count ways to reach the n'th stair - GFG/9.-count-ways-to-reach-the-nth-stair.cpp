// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{   
    
    public:
    int mod = 1e9 + 7;
    
    int countWays(int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        for(int i = 1; i <= n ; i++){
            int x = dp[i - 1];
            int y = 0;
            if(i - 2 >= 0){
                y += dp[i - 2];
            }
            dp[i] = (x + y)%mod;
        }
        
        return dp[n];
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends