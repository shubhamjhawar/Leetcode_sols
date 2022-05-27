// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}// } Driver Code Ends


/*you are required to complete this method*/
int convertFive(int n) {
    int new_number = 0;
    
    while(n){
        
        int d = n%10;
        if(d == 0){
            d = 5;
        }
        new_number = new_number*10 + d;
        n = n/10;
    }
    int ne = 0;
    while(new_number){
        int d = new_number%10;
        ne = ne*10 + d;
        new_number  = new_number/10;
        
    }
    
    return ne;
    // Your code here
}