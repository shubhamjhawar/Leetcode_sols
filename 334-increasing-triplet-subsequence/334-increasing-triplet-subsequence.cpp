class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int s1 = INT_MAX,s2 = INT_MAX, n = nums.size();
        if(n == 1 || n == 2) return false;
        bool res = false;
        for(int i = 0 ; i < n ; i++){
            
            if(nums[i] <= s1){
                s1 = nums[i];
            }
            else if(nums[i] <= s2){
                s2 = nums[i];
            }
            else{
                res = true;
            }
            
        }
        
        return res;
        
    }
};