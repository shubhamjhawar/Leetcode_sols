class Solution {
public:
   
    
   void f(vector<int>& candidates,int start , int end , int target,vector<int>& contri, vector<vector<int>>& res) {
       
       
       //Base Case
       if(target == 0){
           res.push_back(contri);
           return;
       }
       
       //Not Possible any answer case
       if(start > end || target < 0){
           return;
       }
      
       //Recursive case
       //Not Take case
       f(candidates,start+1,end,target,contri,res);
       
       //take case
       if(candidates[start] <= target){
           contri.push_back(candidates[start]);
           f(candidates,start,end,target - candidates[start],contri,res);
           contri.pop_back();
       }
      
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> contri;
        f(candidates,0,candidates.size()-1,target,contri,res);
        return res;
    }
};