class Solution {
public:
    void f(vector<char>& s,int start, int end){
        
        //Base Case
        if(start >= end){
            return;
        }
        
        //Recursive case
        swap(s[start],s[end]);
        
        f(s,start+1,end-1);
        
    }
    void reverseString(vector<char>& s) {
        
        int n = s.size();
        
        f(s,0,n-1);
        
    }
};