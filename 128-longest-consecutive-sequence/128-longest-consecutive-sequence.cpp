class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n == 0 || n == 1) return n;
        int maxi = 1,cnt = 1;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            if(nums[i] == nums[i-1] +1){
                cnt++;
            }
            else{
                maxi = max(maxi,cnt);
                cnt = 1;
            }
        }
        
        return max(maxi,cnt);
    }
};