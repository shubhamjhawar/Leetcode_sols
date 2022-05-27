class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        int n = nums.size();
        long first =  LONG_MIN;
        long second = LONG_MIN;
        long third =  LONG_MIN;
        
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        for(int i = 0 ; i < nums.size() ; i++) {
           
            if (nums[i] == first|| nums[i] == second || nums[i] == third )
                continue;
            
            if(nums[i] > first){
                third = second;
                second = first;
                first = nums[i];
            }
            else if(nums[i] > second) {
                third = second;
                second = nums[i];
            }
            else if(nums[i] >= third){
                third = nums[i];
            }
        }
        
        return third  == LONG_MIN ? first : third ;
        
    }
};