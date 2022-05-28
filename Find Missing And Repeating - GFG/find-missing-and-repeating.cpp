// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        
        sort(arr,arr+n);
        int* nums = arr;
        int miss = 1,rep;
        int* res = new int[2];
        for(int i = 0 ; i < n ; i++){
            if(i+1 < n && nums[i] == nums[i+1]){
                rep = nums[i];
            }
            
            if(arr[i] == miss){
                miss++;
            }
        }
        res[0] = rep;
        res[1] = miss;
        
        
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