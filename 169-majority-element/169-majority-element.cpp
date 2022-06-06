class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elt ,cnt = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(cnt == 0){
                elt = nums[i];
            }
            
            if(elt == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        
        return elt;
    }
};