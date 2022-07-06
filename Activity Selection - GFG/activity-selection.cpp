// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{   private:
    struct meeting{
        int start;
        int end;
        int pos;
    };
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        struct meeting meet[n];
        for(int i = 0 ; i < n ; i++){
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i+1;
        }
        
        sort(meet,meet+n,[=](struct meeting m1,struct meeting m2){
            if(m1.end != m2.end){
                return m1.end < m2.end;
            }
            else{
                return m1.pos < m2.pos;
            }
        });
        
        int cnt = 1;
        int limit = meet[0].end;
        
        for(int i = 0;i < n ; i++){
            if(meet[i].start > limit){
                cnt++;
                limit = meet[i].end;
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends