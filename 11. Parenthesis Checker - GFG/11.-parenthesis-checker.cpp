// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        stack<int> st;
        // Your code here
        for(int i = 0 ; i < s.size() ; i++){
            //Push into the stack
            if(s[i] == '(' or s[i] == '{' or s[i] == '['){
                st.push(s[i]);
              }else{
              //match the pairs
                if((st.empty() == true) or (s[i] == ')' and st.top() !=  '(') or (s[i] == '}' and st.top() !=  '{') or (s[i] == ']' and st.top() !=  '[') ){
                return false;
                }
                else{
                st.pop();
                 }  
            }
        }
        
        return st.empty();
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends