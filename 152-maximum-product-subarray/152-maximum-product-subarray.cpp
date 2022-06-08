class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>maxprod(2,1);
        vector<int>minprod(2,1);
        int res = INT_MIN;
        for(int i = 1 ; i <= nums.size() ; i++){
            maxprod[i%2] = max(nums[i-1],max(nums[i-1]*maxprod[(i-1)%2],nums[i-1]*minprod[(i-1)%2]));
            minprod[i%2] = min(nums[i-1],min(nums[i-1]*maxprod[(i-1)%2],nums[i-1]*minprod[(i-1)%2]));
            
            res = max(res,maxprod[i%2]);
        }
        
        return res;
    }
};