// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
void f (vector<int>& nums , int i , int end,vector<int>& res,int contri)
{

       //base case
       if(i == end){
           res.push_back(contri);
           return;
       }
        
      //Recursive case
      //not take
      f(nums,i+1,end,res,contri);
        
      //Take 
    //   contri.push_back(nums[i]);
      f(nums,i+1,end,res,contri + nums[i]);
    //   contri.pop_back();
          
}
vector<int> subsetSums(vector<int> arr, int N)
{
     
     vector<int> res;
     f(arr, 0 , arr.size(),res,0);
     sort(res.begin(),res.end());
     return res; 
}
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends