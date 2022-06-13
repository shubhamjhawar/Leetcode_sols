class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        
        if( n == 1 )return n;
           
        int last_seen_idx =  0;
           
        for( int i = 0 ; i < nums.size()-1 ; i++ ){
            
            if(nums[i] != nums[i+1]){
              nums[last_seen_idx++] = nums[i];  
            }
            
        }
           
        nums[last_seen_idx] = nums[n-1];
        last_seen_idx++;
        
       return last_seen_idx;
        
    }
};