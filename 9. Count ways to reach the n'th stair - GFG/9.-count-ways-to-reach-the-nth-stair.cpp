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
        vector<int> dp(2, -1);
        dp[0%2] = 1;
        dp[1%2] = 1;
        for(int i = 2; i <= n ; i++){
           dp[i%2] = (dp[(i-1)%2] + dp[(i-2)%2])%mod;
        }
        
        return dp[n%2];
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