class Solution {
public:
    bool f(int n){
        
        if(n == 1){
            return true;
        }
        if(n == 89){
            return false;
        }
        
        int sum = 0;
        while(n){
            int d = n%10;
            sum += d*d;
            n = n/10;
        }
        
        return f(sum);
    }
    bool isHappy(int n) {
        return f(n);
    }
};