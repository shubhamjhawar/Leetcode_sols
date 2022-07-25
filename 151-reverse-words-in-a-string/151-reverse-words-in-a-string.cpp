class Solution {
public:
//     string reverseWords(string s) {
//         stringstream ss(s);
//         string word;
//         string ans  = "";
//         while(ss >> word){
//             ans = word + " " + ans;
//         }
       
//         return ans.substr(0,s.size());
//     }
     string reverseWords(string s) {
        stringstream all(s); 
        string word,ans = "";
        while (all >> word)
            ans = word + " " + ans;
        return ans.substr(0,ans.length()-1);
    }
};