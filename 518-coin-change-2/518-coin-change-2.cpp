class Solution {
public:
     int f(int index,vector<int>& coins, int target,vector<vector<int>>& dp){
        
        //Base case
        if(target == 0){
            return 1;
        }
        
        //Base case when index reaches the last index
        if(index == 0){
            if(target%coins[0] == 0){
                return 1;
            }else{
                return 0;
            }
        }
        
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        
        
        //Recursive case
        int not_take = 0 + f(index-1,coins,target,dp);
        
        int take = 0;
        if(coins[index] <= target){
            take = f(index,coins,target - coins[index],dp);
        }
        
        return dp[index][target] =  take + not_take;
        
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(2,vector<int>(amount+1,-1));
//         int ans = f(n-1,coins,amount,dp);
//         return ans;
        
        for(int target = 0 ;target <= amount ; target++){
           if(target%coins[0] == 0){
               dp[0%2][target] = 1;
           }else{
               dp[0%2][target] = 0;
           }
        }
        
        for(int index = 1 ; index < n ; index++){
            for(int target = 0 ; target <= amount ; target++){
                if(target == 0){
                    dp[index%2][target] = 1;
                }
                
                int not_take = 0 + dp[(index-1)%2][target];
        
                int take = 0;
                if(coins[index] <= target){
                    take = dp[index%2][target - coins[index]];
               }
        
               dp[index%2][target] =  take + not_take;
            }
        }
        
        return dp[(n-1)%2][amount];
    }
};