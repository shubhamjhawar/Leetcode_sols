class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int low = 0,high = n-1,mid = 0;
        while(mid < high){
            if(nums[mid]%2 == 0){
                mid++;
                low++;
            }
            else{
                swap(nums[low],nums[high]);
                high--;
            }
        }
        
        return nums;
    }
};