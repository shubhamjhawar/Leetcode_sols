class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        long long  low = 1,high =  x/2;
        //if pow(number,2) > x
        //Treat it as true as
        //Pattern is F*T* and find the last f
        while(low < high){
            
            long long  mid = low + (high - low + 1)/2;
            
            if((mid*mid) > x){
                high = mid-1;
            }
            else{
                low = mid;
            }
            
        }
        
        return low;
        
    }
};