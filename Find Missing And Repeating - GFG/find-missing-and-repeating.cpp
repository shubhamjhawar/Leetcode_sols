// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
       int runXor = 0,i;
       int* res = new int[2];
       for(i = 0 ; i < n ; i++){
           runXor ^= arr[i];
           runXor ^= i+1;
       }
       
       //X^Y = runXor;
       
       int set_bit_no = runXor & ~(runXor - 1);
       
       
       int bucket1 = 0;
       int bucket2 = 0;
       
       for(i = 0 ; i < n ; i++){
           if(arr[i]&set_bit_no){
               bucket1 ^= arr[i];
           } 
           else{
              bucket2 ^= arr[i]; 
           }
              
       }
       
       for (i = 1; i <= n; i++)
       {
        if (i & set_bit_no)
            bucket1 ^= i;
        else
            bucket2 ^= i;
       }
    
    //   cout << bucket1 << "   " << bucket2 << endl;
       
       int x_count = 0;
        for (int i=0; i<n; i++) {
        if (arr[i]== bucket1)
            x_count++;
        }
        
        if(x_count){
            res[0] = bucket1;
            res[1] = bucket2;
            return res;
        }
        
        res[0] = bucket2;
        res[1] = bucket1;
        
        return res;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends