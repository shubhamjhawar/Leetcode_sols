///Based on this 
//nck = n-1Ck-1 + n-1Ck;
class Solution {
public:
        
     void f (vector<int>& nums , int index , int end,vector<vector<int>> & res,vector<int>& contri,int target)
    {
        if(target == 0){
            res.push_back(contri);
            return;
        }
        
        for(int i = index ; i < nums.size() ;i++)
        {
            if(i != index and nums[i] == nums[i-1]) continue;
            //Condition check
            if(nums[i] > target) break;
            
            contri.push_back(nums[i]);
            f(nums,i+1,end,res,contri,target - nums[i]);
            contri.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     vector<vector<int>> res;
     vector<int> contri;
     sort(candidates.begin(),candidates.end());
     f(candidates, 0 , candidates.size(),res,contri,target);
     return res;
        
    }
};