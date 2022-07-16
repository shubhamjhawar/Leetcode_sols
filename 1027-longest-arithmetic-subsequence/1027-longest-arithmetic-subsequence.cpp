class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(1001,1));
        

        int res = 2;
        for(int index = 0 ; index < n ; index++){
            for(int prev_index = 0 ; prev_index < index ; prev_index++){
                int cd = nums[index] - nums[prev_index];
                
                dp[index][cd+500] = max(1 + dp[prev_index][cd+500],dp[index][cd+500]);
                
                res = max(res,dp[index][cd+500]);
               }
            }
        
            return res;
          
        }
};