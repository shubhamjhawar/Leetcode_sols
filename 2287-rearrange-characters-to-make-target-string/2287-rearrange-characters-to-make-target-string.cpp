class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> tg(26,0);
        for(auto &ch : target){
            tg[ch - 'a']++;
        }
        
       vector<int> searchstr(26,0);
       for(auto& x :s){
           searchstr[x - 'a']++;
       }
        
       int mini = INT_MAX;
        
       for(auto& ch : target){
           mini = min(mini,searchstr[ch - 'a']/tg[ch - 'a']);
       }
        
       return mini;
    }
};