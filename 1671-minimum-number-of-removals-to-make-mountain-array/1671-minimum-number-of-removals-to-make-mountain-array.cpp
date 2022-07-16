class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n+1,1);
        
        
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            for(int j = i-1 ; j >= 0 ; j--){
                if(nums[i] > nums[j] and dp1[j] + 1 > dp1[i]){
                    dp1[i]  = dp1[j] + 1;
                }
            }
            
        }
        
        vector<int> dp2(n+1,1);
        
        
        
        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int j = n-1 ; j > i ; j--){
                if(nums[i] > nums[j] and dp2[j] + 1 > dp2[i]){
                    dp2[i]  = dp2[j] + 1;
                }
            }
            
        }
        
        
        int maxi = 0;
        
        for(int i = 1; i < n-1 ; i++){
            if(dp1[i] > 1 and dp2[i] > 1)
                maxi = max(dp1[i] + dp2[i] - 1,maxi);
        }
        
        for(int i = 0 ; i < n ; i++){
            cout << dp1[i] << " ";
            
        }
        
        cout << endl;
        for(int i = 0 ; i < n ; i++){
            cout << dp2[i] << " ";
        }
        
        cout << endl;
        return n - maxi;
    }
};