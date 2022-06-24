class Solution {
public:
    void f (vector<int>& nums , int i , int end,vector<vector<int>>& res,vector<int>& contri)
    {

       //base case
       if(i == end){
           res.push_back(contri);
           return;
       }
        
    
    
    
      //Recursive case
      //not take
      f(nums,i+1,end,res,contri);
        
      //Take 
      contri.push_back(nums[i]);
      f(nums,i+1,end,res,contri);
      contri.pop_back();
          
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
    
     vector<vector<int>> res;
     vector<int> contri;
     f(nums, 0 , nums.size(),res,contri);
        
     return res; 
    }
};