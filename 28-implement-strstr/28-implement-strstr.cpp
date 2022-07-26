class Solution {
public:
//Kmp algorithm
void f(string& pattern,vector<int>& res){
        int j = 0;
        res[0]  =  0;
        int i  =   1;
        while(i < pattern.length()) {
            if(pattern[i] == pattern[j]) {
                res[i] = j+1;
                i++;
                j++;
            } 
            else if (j > 0) {
                j = res[j-1];
            }
            else {
                  res[i] = 0;
                  i++;
            }
        }
    
    }
    int strStr(string haystack, string needle) {
        
        //Computing the LCP
        int n = needle.size();
        vector<int> res(n,0);
        f(needle,res);
        
        int i = 0,j = 0;
        //Implement kmp search 
        while(i < haystack.size() && j < needle.size()) {
            if(haystack.at(i) == needle.at(j)) {
                i++; 
                j++;
            } else if(j > 0) {
                j = res[j - 1];
            } else {
                i++;
            }
        }
        
        return j == needle.size() ? i - j : -1;
        
        
    }
};