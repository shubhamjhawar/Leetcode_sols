class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(),res;
        vector<int> dp(n);
        
        dp[0] = nums[0];
        res = dp[0];
        
        for(int i = 1 ; i <n ; i++){
            
            dp[i] = max(dp[i-1] + nums[i],nums[i]);
            res = max(dp[i],res);
            
        }
        
        return res;
        
    }
};