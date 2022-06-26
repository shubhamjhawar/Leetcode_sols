class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> mp;
        
        for(auto x : nums){
            mp.insert(x);
             if (mp.size() > 3){
                 mp.erase(mp.begin());
              }
        }
        return mp.size() == 3 ? *mp.begin() : *mp.rbegin();
    }
};