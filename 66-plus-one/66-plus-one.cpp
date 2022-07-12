class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        int i = n-1;
        int carry = 1;
        while(i >= 0 and carry > 0){
            int number = digits[i] + carry;
            carry = number/10;
            digits[i] = number%10;
            i--;
        }
        
        if(carry){
            digits[0] = 1;
            digits.push_back(0);
            return digits;
        }
        else{
            return digits;
        }
        
    }
};