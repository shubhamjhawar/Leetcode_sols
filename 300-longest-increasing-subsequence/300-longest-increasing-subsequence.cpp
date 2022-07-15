class Solution {
public:
    int LIS(vector<int>& nums,vector<int>& dp){
        
        int n = nums.size();
        int max_len = 1;
        vector<int> hash(n);
        
       int last_index = 0;
       for(int index = 0 ; index < n ; index++){
           hash[index] = index;
           for(int prev_index = 0 ; prev_index < index ; prev_index++){
               if(nums[prev_index] < nums[index] and dp[index] < 1 + dp[prev_index]){
                   dp[index] = 1 + dp[prev_index];
                   
                   hash[index] = prev_index;
               }
           }
           if(dp[index] > max_len){
               max_len = dp[index];
               last_index = index;
           }
       } 
        
      cout << last_index << endl;
      // for(int i = 0 ; i < n ; i++){
      //     cout << hash[i] << " ";
      // }
        
      vector<int> temp;
      temp.push_back(nums[last_index]);
        
        
      while(hash[last_index] != last_index){
          last_index = hash[last_index];
          temp.push_back(nums[last_index]);
      }
      
      reverse(temp.begin(),temp.end());
        
      for(auto it : temp){
          cout << it << " ";
      }
     
    
      cout << endl;
      return max_len;
     
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        return LIS(nums,dp);
    }
};