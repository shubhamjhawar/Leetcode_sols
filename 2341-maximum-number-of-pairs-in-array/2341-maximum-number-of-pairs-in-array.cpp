class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(auto& x: nums){
            mp[x]++;
        }
        
        int pairs = 0;
        int leftover = 0;
        for(auto& it : mp){
            int cnt = it.second;
            pairs += cnt/2;
            leftover += cnt%2;
        }
        
       return {pairs,leftover};
        
    }
};