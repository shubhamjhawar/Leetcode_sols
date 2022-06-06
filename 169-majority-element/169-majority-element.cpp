class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int required = floor(n/2);
        for(auto x : nums){
            mp[x]++;
            if(mp[x] > required){
                return x;
            }
            cout << mp[x] << " " << x << endl;
        }
        
        return -1;
    }
};