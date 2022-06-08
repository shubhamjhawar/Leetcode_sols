class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(),res = INT_MIN,i;
        int  curr = 0,prev = 0;
        for(i = 1 ; i <= n ; i++){
            curr = max(prev + nums[i-1],nums[i-1]);
            prev = curr;
            res = max(res,curr);
        }
        
        return res;
    }
};