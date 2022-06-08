class Solution {
public:
    bool f(vector<int>& arr,int k,int n, vector<vector<bool>>& dp){
    
    
    
    if(arr[0]<=k)
      dp[0][arr[0]] = true;
    
    for(int i = 1; i < n ;i++){
         dp[i][0] = true;
        for(int target = 1 ; target <= k ; target++){
            bool not_take = dp[(i-1)][target];
            bool take = false;
            if(arr[i] <= target){
                take = dp[(i-1)][target - arr[i]];
            }
            
            dp[i][target] = take || not_take ;
        }
    }
    
    return dp[(n-1)][k];
}
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    if (nums.size() == 0) return false;
    int k;
    int S = accumulate(nums.begin(),nums.end(),0);
    if(S%2) 
        return false;
    else
        k = S/2;
    vector<vector<bool>> dp (n, vector<bool>(k+1, false));
    return f(nums,k,n,dp);
    }
};