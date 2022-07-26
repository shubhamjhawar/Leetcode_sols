class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        if(strs.size() == 1) return strs[0];
        string first = strs[0];
        string last  = strs[strs.size()-1];
        int i = 0 , j = 0;
        while(i < first.size() and j < last.size()){
            if(first[i] == last[j]){
                i++;
                j++;
            }else{
                break;
            }
        }
        
        return i == 0 ? "" : first.substr(0,i);
        
    }
};