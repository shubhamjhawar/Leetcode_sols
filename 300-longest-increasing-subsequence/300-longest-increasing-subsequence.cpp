class Solution {
public:
    int LIS(vector<int>& nums,vector<vector<int>>& dp){
        
        int n = nums.size();
    
        for(int index = n-1 ; index >= 0 ; index--){
            for(int prev_index = index-1 ; prev_index >= -1 ; prev_index--){
                //Not take
                int len = 0 + dp[index+1][prev_index+1];
                
                //Take case
                if(prev_index == -1 || nums[index] > nums[prev_index]){
                     len = max(len,1 + dp[index+1][index+1]);
                }
                 dp[index][prev_index+1] = len;
            }
        }
        
        
        return dp[0][0];
     
}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        return LIS(nums,dp);
    }
};