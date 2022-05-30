class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> res;
        for(int i = left ; i <= right ; i++){
            int n = i;
            int number = i;
            bool flag = true;
            while(n){
                int d = n%10;
                
                if(d == 0 || number%d != 0){
                    flag = false;
                    break;
                }
                
                n = n/10;
            }
            
            if(flag){
                res.push_back(number);
            }
        }
        
        return res;
        
    }
};