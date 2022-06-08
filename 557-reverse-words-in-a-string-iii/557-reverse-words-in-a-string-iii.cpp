class Solution {
public:
    string reverseWords(string s) {
        
     s = s + " ";
    
     int j = 0,k = 0;
     for(int i = 0 ; i < s.size() ; i++){
         if(s[i] == ' '){
             reverse(s.begin()+ k,s.begin()+ j);
             k = i+1;
             j++;
         }
         else{
             j++;
         }
     }
     s.erase(s.size()-1,1);
     return s;
        
    }
};