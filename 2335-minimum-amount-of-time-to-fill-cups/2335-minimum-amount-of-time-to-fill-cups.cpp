class Solution {
public:
    int fillCups(vector<int>& amount) {
         sort(amount.begin(),amount.end());
        
         int res = 0;
         while(amount[2] != 0){
          amount[2]--;
          res++;
         if(amount[1] > 0){
             amount[1]--;
         }
             
         sort(amount.begin(),amount.end());
             
        }
    
        return res;
    }
};