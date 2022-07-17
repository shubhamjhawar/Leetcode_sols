class Solution {
public:
    void f (vector<int>& nums , int index , int end,vector<vector<int>>& res,vector<int>& contri)
    {

        res.push_back(contri);
        
        for(int i = index ; i < nums.size() ;i++)
        {
            contri.push_back(nums[i]);
            f(nums,i+1,end,res,contri);
            contri.pop_back(); 
        }
          
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
    
     vector<vector<int>> res;
     vector<int> contri;
     f(nums, 0 , nums.size(),res,contri);
        
     return res; 
    }
};