class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sArr(26,0);
        vector<int> tArr(26,0);
        for(auto ch : s){
            sArr[ch - 'a']++;
        }
        
        for(auto charac : t){
            tArr[charac - 'a']++;
        }
        
        return sArr == tArr;
    }
};