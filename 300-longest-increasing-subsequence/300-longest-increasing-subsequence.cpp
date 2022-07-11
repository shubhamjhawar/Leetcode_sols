class Solution {
public:
    int LIS(vector<int>& nums,vector<int>& dp){
        
        int n = nums.size();
        int max_len = 1;
       for(int index = 0 ; index < n ; index++){
           for(int prev_index = 0 ; prev_index < index ; prev_index++){
               if(nums[prev_index] < nums[index]){
                   dp[index] = max(dp[prev_index] + 1,dp[index]);
               }
           }
           max_len = max(max_len,dp[index]);
       } 
        
      return max_len;
     
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        return LIS(nums,dp);
    }
};