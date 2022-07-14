// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int f(vector<int>& arr,int target,int index,vector<vector<int>>& dp){
        if(target == 0) return 1;
        if(index == 0){
           if(arr[0] == target) 
               return 1; 
           else
               return 0;
        }
        
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        
        //Recursive case
        int not_take = f(arr,target,index-1,dp);
        
        int take = 0;
        if(arr[index] <= target){
             take = f(arr,target - arr[index],index-1,dp);
        }
        
        return dp[index][target] =  take or not_take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return f(arr,sum,n-1,dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends