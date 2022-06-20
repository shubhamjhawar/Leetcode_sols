class symbolMap{

   private:
      vector<string> m ;
    public:
    symbolMap(){
           m.resize(1001);

            m[1] = "I";
            m[4] = "IV";
            m[5] = "V";
            m[9] = "IX";
            m[10] = "X";
            m[40] = "XL";
            m[50] = "L";
            m[90] = "XC";
            m[100] = "C";
            m[400] = "CD";
            m[500] = "D";
            m[900] = "CM";
            m[1000] = "M";

    }
    
    string getSymbol(int val){
        return m[val];
    }
    
    vector<int> getAllValues(){
        return { 1, 4 ,  5 , 9 , 10 , 40 , 50 ,90, 100 , 400 , 500 , 900 , 1000 };
    }
    
};
class Solution {
public:
    string intToRoman(int num) {
         symbolMap sm;
         string res = "";
         vector<int> val = sm.getAllValues();
        
         for(int i = val.size()-1 ; i >= 0 ; i--){
             int d = num/val[i];
             string symbol = sm.getSymbol(val[i]);
             while(d){
                 res += symbol;
                 d--;
             }
             num = num%val[i];
         }
        
        return res;
    }
};