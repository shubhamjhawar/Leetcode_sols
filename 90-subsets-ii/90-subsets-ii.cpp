class Solution {
public:
     void f (vector<int>& nums , int i , int end,set<vector<int>> & res,vector<int> contri)
    {

       //base case
       if(i == end){
           sort(contri.begin(),contri.end());
           res.insert(contri);
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
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     set<vector<int>> res;
     vector<int> contri;
     f(nums, 0 , nums.size(),res,contri);
     vector<vector<int>> ans(res.begin(),res.end());
     return ans;
    }
};