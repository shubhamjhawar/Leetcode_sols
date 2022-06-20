class Solution {
public:
    int getValue(char c){
         if (c == 'I')
            return 1;
         else if (c == 'V')
            return 5;
         else if (c == 'X')
            return 10;
         else if (c == 'L')
            return 50;
         else if (c == 'C')
            return 100;
         else if (c == 'D')
            return 500;
         else 
          return 1000;     
    }
    int romanToInt(string s) {
        
        int res = 0;
        for(int i = 0 ; i < s.size()-1 ; i++){
            if(getValue(s[i]) < getValue(s[i+1])){
                res += -1*(getValue(s[i]));
            }
            else{
                res += getValue(s[i]);
            }
        }
        
        res += getValue(s[s.size()-1]);
        
        return res;
    }
};