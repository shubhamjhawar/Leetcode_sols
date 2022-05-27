class Solution {
    int cnt = 0;
public:
    int numberOfSteps(int num) {
    
        if(num == 0){
            return 0;
        }
        
        //recursive case
        if(num%2){
           cnt = 1 + numberOfSteps(num-1);
        }
        else{
            cnt = 1 + numberOfSteps(num/2);
        }
        
        return cnt;
    }
};