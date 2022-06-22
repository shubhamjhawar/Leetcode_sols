class Solution {
public:
string getIdentifier(string &s){
            vector<int>freq (26,0) ;
           
           for(auto &ch : s) {
               freq[ch - 'a']++;
           }
           
           string res = "";
           
           for(int i = 0 ; i < 26 ; i++) {
               res += to_string(freq[i]) + "#";
           }
           
           return res;
}   
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        //Result is this
        vector<vector<string>> res ;
        //map to int to the numbers
        unordered_map<string,int> m ;
        
        
        for(int i = 0 ; i < strs.size() ; i++) {
            //get the group identifier
            string id = getIdentifier(strs[i]);
            
            
            //If this is the first element the group
            if(m.find(id) == m.end()){
               m[id]  = res.size();
                
               res.push_back({});
               
            }
            //if not the first element
        
            res[m[id]].push_back(strs[i]);
        
        }

        return res;
    }
};