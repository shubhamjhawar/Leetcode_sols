class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot,i;
        for(pivot = n-2 ; pivot >= 0 ;pivot--){
            if(nums[pivot] < nums[pivot+1] ){
                break;
            }
        }
        if(pivot < 0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(i = n-1 ; i > pivot ; i--){
                if(nums[i] > nums[pivot]){
                    break;
                }
            }
            
            swap(nums[pivot],nums[i]);
        
        reverse(nums.begin() + pivot + 1,nums.end());
        }
    
    }
};