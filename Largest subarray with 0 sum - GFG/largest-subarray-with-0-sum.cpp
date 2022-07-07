// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int j = 0;
        int maxi = 0;
        unordered_map<int,int> mp;
        int sum = 0;
        while(j < n){
            sum += A[j];
            if(sum == 0){
                maxi = j+1;
            }
            else{
                if(mp.find(sum) == mp.end()){
                    mp[sum] = j;
                }
                else{
                   maxi = max(maxi,j - mp[sum]); 
                }
            }
            j++;
        }
        
        return maxi;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends