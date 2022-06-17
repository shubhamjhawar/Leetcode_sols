class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n == 0 || n == 1) return n;
        int maxi = 1,cnt = 1;
        for(int i = 1 ; i < n-1 ; i++){
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
        if(nums[n-1] == nums[n-2] + 1){
            maxi = max(maxi,cnt+1);
        }
        else{
            maxi = max(maxi,cnt);
        }
        
        return maxi;
    }
};