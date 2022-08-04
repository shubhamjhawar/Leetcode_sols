class Solution {
public:
    int f(int index,vector<int>& coins, int target,vector<vector<int>>& dp){
        
        //Base case
        if(index == 0){
            if(target%coins[0] == 0){
                return target/coins[index];
            }else{
                return 1e9;
            }
        }
        
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        
        
        //Recursive case
        int not_take = 0 + f(index-1,coins,target,dp);
        
        int take = 1e9;
        if(coins[index] <= target){
            take = 1 + f(index,coins,target - coins[index],dp);
        }
        
        return dp[index][target] =  min(take,not_take);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1,coins,amount,dp);
        if(ans >= 1e9){
            return -1;
        }else{
            return ans;
        }
    }
};