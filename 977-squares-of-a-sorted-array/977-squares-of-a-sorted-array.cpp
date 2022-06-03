class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int last_seen = n-1;
        int low = 0 ,high = n-1;
        
        while(low <= high){
            if(abs(nums[low]) < abs(nums[high])){
                res[last_seen] = nums[high]*nums[high];
                high--;
                last_seen--;
            }
            else{
                res[last_seen] = nums[low]*nums[low];
                low++;
                last_seen--;
            }
        }
        
        return res;
    }
};