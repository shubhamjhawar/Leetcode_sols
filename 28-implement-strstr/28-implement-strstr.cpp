class Solution {
public:
    bool check(string& haystack,int i ,int j,string& needle){
        int sz = needle.size();
        while(i <= j){
            if(haystack[i] != needle[sz - (j-i+1)])
                return false;
            
            i++;
        }
        
        return true;
    }
    int strStr(string haystack, string needle) {
        int k = needle.size();
        int i = 0, j = 0;
        bool flag = false;
        while(j < haystack.size()){
            if(j - i + 1 < k){
                j++;
            }
            else if(j - i + 1 == k){
                bool isEqual = check(haystack,i,j,needle);
                if(isEqual) {
                    flag = true;
                     break;
                }
                   
                i++;
                j++;
            }
                
        }
        
        if(flag) 
            return i;
        else 
            return -1;
    }
};