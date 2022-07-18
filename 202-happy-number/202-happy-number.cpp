class Solution {
public:
    bool f(int n,unordered_set<int>& mp){
        
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
        
        mp.insert(sum);
        return f(sum,mp);
    }
    bool isHappy(int n) {
        unordered_set<int> mp;
        return f(n,mp);
    }
};