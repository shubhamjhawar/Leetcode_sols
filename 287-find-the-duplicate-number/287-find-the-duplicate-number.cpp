class Solution {
public:
    //Floyd warshall Cycle detection Method as a whole
    //Works here which takes O(n and O(1) spa)
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast != slow);
            
        fast = nums[0];
        
        while(fast != slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return  slow;
    }
};