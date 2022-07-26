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
        
        //Sliding Window Technique as a whole
        while(j < haystack.size()){
            
            //Keep sliding the window till it
            //becomes the appropriate size
            if(j - i + 1 < k){
                j++;
            }
            //if Window size == k
            //Check if the first element itself is not equal 
            else if(j - i + 1 == k){
                if(haystack[i] != needle[0]){
                    i++;
                    j++;
                }
            else{
                 bool isEqual = check(haystack,i,j,needle);
                  if(isEqual) {
                    flag = true;
                     break;
                   }
                  i++;
                  j++;  
              }  
          }
                
        }
        
        if(flag) 
            return i;
        else 
            return -1;
    }
};