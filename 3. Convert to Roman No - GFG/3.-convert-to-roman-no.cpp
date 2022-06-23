// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class symbolMap{

   private:
      vector<string> m ;
    public:
    symbolMap(){
           m.resize(1001);

            m[1] = "I";
            m[4] = "IV";
            m[5] = "V";
            m[9] = "IX";
            m[10] = "X";
            m[40] = "XL";
            m[50] = "L";
            m[90] = "XC";
            m[100] = "C";
            m[400] = "CD";
            m[500] = "D";
            m[900] = "CM";
            m[1000] = "M";

    }
    
    string getSymbol(int val){
        return m[val];
    }
    
    vector<int> getAllValues(){
        return { 1, 4 ,  5 , 9 , 10 , 40 , 50 ,90, 100 , 400 , 500 , 900 , 1000 };
    }
    
};
class Solution{
  public:
    string convertToRoman(int n) {
        // code here
         int num = n;
         symbolMap sm;
         string res = "";
         vector<int> val = sm.getAllValues();
        
         for(int i = val.size()-1 ; i >= 0 ; i--){
             int d = num/val[i];
             string symbol = sm.getSymbol(val[i]);
             while(d){
                 res += symbol;
                 d--;
             }
             num = num%val[i];
         }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		Solution ob;
    	cout << ob.convertToRoman(N) << endl;
	}
	return 0;
}  // } Driver Code Ends