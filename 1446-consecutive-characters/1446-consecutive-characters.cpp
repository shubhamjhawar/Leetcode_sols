class Solution {
public:
    int maxPower(string s) {
        
        int maxLen = 1,cnt = 1;
        for(int i = 1 ; i < s.size() ; i++){
            if(s[i] != s[i-1]){
                cnt = 1;
            }
            else{
                cnt++;
                maxLen = max(maxLen,cnt);
            }
        }
        return maxLen;
        
    }
};