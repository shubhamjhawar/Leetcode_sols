class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        int max_len = 1;
        vector<int> hash(n),dp(n,1);
        sort(nums.begin(),nums.end());
       int last_index = 0;
       for(int index = 0 ; index < n ; index++){
           hash[index] = index;
           for(int prev_index = 0 ; prev_index < index ; prev_index++){
               if(nums[index]%nums[prev_index] == 0 and dp[index] < 1 + dp[prev_index]){
                   dp[index] = 1 + dp[prev_index];
                   
                   hash[index] = prev_index;
               }
           }
           if(dp[index] > max_len){
               max_len = dp[index];
               last_index = index;
           }
       } 
        
     
        
      vector<int> temp;
      temp.push_back(nums[last_index]);
        
        
      while(hash[last_index] != last_index){
          last_index = hash[last_index];
          temp.push_back(nums[last_index]);
      }
      
      reverse(temp.begin(),temp.end());
        
      return temp;
       
    }
};