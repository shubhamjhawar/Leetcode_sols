// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    int thirdLargest(int a[], int n)
    {
         //Your code here
        int* nums = a;
        long first =  LONG_MIN;
        long second = LONG_MIN;
        long third =  LONG_MIN;
        
        if(n < 3) return -1;
        for(int i = 0 ; i < n ; i++) {
           
            if (nums[i] == first|| nums[i] == second || nums[i] == third )
                continue;
            
            if(nums[i] > first){
                third = second;
                second = first;
                first = nums[i];
            }
            else if(nums[i] > second) {
                third = second;
                second = nums[i];
            }
            else if(nums[i] >= third){
                third = nums[i];
            }
        }
        
        return third  == LONG_MIN ? first : third ;
    }

};

// { Driver Code Starts.
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution obj;
	    cout<<obj.thirdLargest(a,n)<<endl;
    }
}     // } Driver Code Ends