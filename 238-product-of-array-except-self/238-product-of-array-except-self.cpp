class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> suff(n,1);
        suff[n-1] = nums[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            suff[i] = suff[i+1]*nums[i];
        }
        
        //Let us use suff array as the result array itself
        
        int cum_prod = 1;
        for(int i = 0 ;i < nums.size()-1 ; i++){
            suff[i] = cum_prod*suff[i+1];
            cum_prod *= nums[i];
        }
        
        suff[n-1] = cum_prod;
        
        
        return suff;
    }
};