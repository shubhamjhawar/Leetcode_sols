// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int index1 = -1,index2 = -1,ans = INT_MAX;
        for(int i = 0 ; i  < n ; i++){
            if(a[i] == x){
                index1 = i;
            }
            
            if(a[i] == y){
                index2 = i;
            }
            
            if(index1 != -1 && index2 != -1){
                ans = min(ans,abs(index1 - index2));
            }
        }
        
        if(index2 == -1 or index1 == -1){
            return -1;
        }
        else{
            return ans;
        }
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
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}
  // } Driver Code Ends