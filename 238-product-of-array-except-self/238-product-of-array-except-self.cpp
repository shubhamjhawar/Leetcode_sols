class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
     int n = nums.size();
     vector<int>out(nums.size(),1);
     out[n-1] = nums[n-1];
     for(int i = n-2 ; i >= 0 ; i--){
         out[i] = out[i+1]*nums[i];
     }
        
     int cum = 1;
     for(int i = 0 ;i < n-1 ; i++){
         out[i] = out[i+1]*cum;
         cum = cum*nums[i];
     }
     out[n-1] = cum;
        
     return out;
        
    }
};