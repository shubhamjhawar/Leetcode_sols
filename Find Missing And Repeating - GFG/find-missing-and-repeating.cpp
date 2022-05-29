// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int* res = new int[2];
        int* lookup = new int[n+1]{0} ;
        int miss,rep;
        for(int i = 0 ; i < n ; i++){
            if(lookup[arr[i]] == 0){
                lookup[arr[i]] += 1;
            }
            else{
                rep = arr[i];
            }
        }
        for(int i = 1 ; i < n+1 ; i++){
            if(lookup[i] == 0){
                miss = i;
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