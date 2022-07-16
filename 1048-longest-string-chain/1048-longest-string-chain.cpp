class Solution {
public:
    bool compare(string& x ,string& y){
        
        if(x.size() != y.size()+1) return false;
        int i = 0, j = 0;
        int m = x.size();
        int n = y.size();
        int onematch = true;
        while(i < m ){
            if(x[i] == y[j]){
                i++;
                j++;
            }
           
            else{
                i++;
            }
        }
        
       if(i == x.size() and j == y.size()) 
            return true;
        else
            return false;
       
    }
    int longestStrChain(vector<string>& nums) {
        
        int n = nums.size();
        vector<int> dp(n+1,1);
        int res = 1;
        sort(nums.begin(),nums.end(),[=](string& a,string& b){
           return a.size()   < b.size();
        });
        for(int i = 0 ; i < nums.size() ; i++)
        {
            for(int j = i-1 ; j >= 0 ; j--){
                if(compare(nums[i],nums[j]) and dp[j] + 1 > dp[i]){
                    dp[i]  = dp[j] + 1;
                }
            }
            
            res = max(dp[i],res);
        }
        
        return res;
    }
    
};