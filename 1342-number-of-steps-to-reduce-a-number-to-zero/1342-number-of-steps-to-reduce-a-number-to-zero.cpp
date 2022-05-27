class Solution {
public:
    int numberOfSteps(int num) {
    
        int cnt = 0;
        while(num){
            if(num%2){
                num = num-1;
                cnt++;
            }
            else{
                num = num/2;
                cnt++;
            }
        }
        
        return cnt;
        
    }
};