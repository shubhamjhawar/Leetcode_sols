// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int shouldPunish (int roll[], int marks[], int n, double avg)
    {
        bool swapped;
        int cnt = 0,mini = 0,sum = 0;
        for(int i = 0 ; i < n ; i++){
        
        //Last i elements are already inplace
        swapped = true;
        for(int j = 0 ; j < (n-i-1) ; j++){
            if(roll[j] > roll[j+1]){
                swapped = false;
                cnt++;
                swap(roll[j],roll[j+1]);
            }
        }
        
        
        if(swapped == true){
            break;
        }
        
      }
      
       for(int a=0; a<n; a++)

        {

            sum = sum + marks[a];

        }
        
        mini = (sum-cnt)/n;
        if(mini < avg){

            return 0;

        }

        else{

            return 1;

        }
        
        
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		double avg; cin >> avg;

		int roll[n];
		int marks[n];

		for (int i = 0; i < n; ++i)
			cin >> roll[i];
		for (int i = 0; i < n; ++i)
			cin >> marks[i];
        Solution ob;
		cout << ob.shouldPunish (roll, marks, n, avg) << endl;
	}
}
  // } Driver Code Ends