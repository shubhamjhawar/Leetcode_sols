class Solution {
public:
    int f(int i1,int i2,vector<vector<int>>& dp,string& text1, string& text2){
        
        //Base case
        if(i1 == 0 || i2 == 0){
            return 0;
        }
        
        if(dp[i1][i2] != -1){
            return dp[i1][i2];
        }
        
        
        //Recursive case
        if(text1[i1-1] == text2[i2-1]){
            return dp[i1][i2] = 1 + f(i1-1,i2-1,dp,text1,text2);
        }
        
        return dp[i1][i2] =  max(f(i1,i2-1,dp,text1,text2),f(i1-1,i2,dp,text1,text2));
         
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        
        return f(n1,n2,dp,text1,text2);
    }
};