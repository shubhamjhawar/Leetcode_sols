class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(),res = INT_MIN;
       
        int prev = 0,curr;
        for(int i = 1 ; i <= n ; i++){
            
            curr = max(prev + nums[i-1],nums[i-1]);
            res = max(res,curr);
            prev =  curr;
            
        }
        
        return res;
        
    }
};