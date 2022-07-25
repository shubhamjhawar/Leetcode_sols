class Solution {
public:
    int lengthOfLastWord(string s) {
       stringstream ss(s);
       string word;
       int cnt = 0;
        
       while(ss >> word){
          // cout << word << endl;
       }
        
       return word.size();
    }
};