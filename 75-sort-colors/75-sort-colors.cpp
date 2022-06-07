class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int cnt1 = 0 ,cnt2 = 0, cnt0 = 0;
        
        for(int x : nums){
            if(x == 0){
                cnt0++;
            }
            else if(x == 1){
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        
    for(int i = 0; i < cnt0; ++i) nums[i] = 0;
    for(int i = 0; i < cnt1; ++i) nums[cnt0+i] = 1;
    for(int i = 0; i < cnt2; ++i) nums[cnt0+cnt1+i] = 2;
        
        
    }
};