class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int lastseenzeroidx = 0;
        int n = nums.size();
        
        for(int i = 0; i < n ; i++){
            if(nums[i]){
                nums[lastseenzeroidx] = nums[i];
                
                lastseenzeroidx++;
            }
        }
        
        for(int i = lastseenzeroidx ; i< n ;i++){
            nums[i] = 0;
        }
        
        
        
    }
};