class Solution {
public:
    int LIS(vector<int>& nums,vector<int>& dp){
        
        vector<int> temp;
        temp.push_back(nums[0]);
        
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int index = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[index] = nums[i];
            }
        }
     
        
        return temp.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        return LIS(nums,dp);
    }
};