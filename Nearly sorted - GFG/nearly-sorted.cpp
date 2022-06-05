// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        priority_queue<int,vector<int>,greater<int>> minhp;
	    int tail = 0;
	    vector<int> res;
	    for(int i = 0 ; i < num; i++){
	        minhp.push(arr[i]);
	        
	        if(minhp.size() > K){
	           res.push_back(minhp.top());
	           minhp.pop();
	        }
	    }
	    
	   while(!minhp.empty()){
	     res.push_back(minhp.top());
	     minhp.pop();
	   }
	   
	   return res;
	    
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends