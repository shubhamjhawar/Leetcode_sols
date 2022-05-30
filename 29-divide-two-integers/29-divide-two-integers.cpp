class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor){
            return 1;
        }
        bool isPositive = (dividend<0 == divisor<0);
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int ans = 0;
        while(a >= b){
            int q = 0;
            
            while(a > (b<<q+1)){
                q++;
            }
            
            ans += 1<<q;  // add the power of 2 found to the answer
            a = a - (b<<q); 
        }
        
        if(ans == (1<<31) and isPositive)   // if ans cannot be stored in signed int
            return INT_MAX;
        return isPositive ? ans : -ans;
        
    }
};