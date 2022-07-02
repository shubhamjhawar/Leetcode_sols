class Solution {
public:
     void f(int start,int end,int k,vector<int>& contri,vector<vector<int>>& res){
       //Base case
         
        if(k == 0){
            res.push_back(contri);
            return;
        }
         
        if(start > end){
            return;
        }
        
          //Take the first element and insert it into the conri vector as a whole
         contri.push_back(start);
         f(start+1,end,k-1,contri,res);
         contri.pop_back();
 
         
         //Dont take the first element as a whole
         f(start+1,end,k,contri,res);
        
         
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>contri;
        vector<vector<int>> res;
        f(1,n,k,contri,res);
        return res;
    }
};