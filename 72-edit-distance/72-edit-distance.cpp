class Solution {
public:
    int f(int i ,int j ,string& word1, string& word2,vector<vector<int>>& dp){
        
        if(i == 0) return j;
        if(j == 0) return i;
        
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        //Recursive case
        if(word1[i-1] == word2[j-1]){
            return dp[i][j] =  0 + f(i-1,j-1,word1,word2,dp);
        }
        
        //Insert 
        int ins = f(i,j-1,word1,word2,dp) + 1;
        
        //Delete
        int del = f(i-1,j,word1,word2,dp) + 1;
        
        //Replace
        int rep = f(i-1,j-1,word1,word2,dp) + 1;
        
        return dp[i][j] = min(ins,min(del,rep));
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(word1.size(),word2.size() ,word1,word2,dp);
    }
};