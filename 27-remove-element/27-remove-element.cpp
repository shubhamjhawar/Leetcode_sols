class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int lastseenelt = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            
            if(nums[i] != val) {
            nums[lastseenelt++] = nums[i];
            }
           
        }
        
        
        int ans = lastseenelt;
       
         return ans;
        
    }
};