class Solution {
public:
      int f(int i1,int i2,vector<vector<int>>& dp,string& text1, string& text2,string& SCS){
    
        
        for(int  j = 0 ; j <= i2 ; j++)dp[0][j] = 0;
        for(int i = 0 ; i <= i1 ; i++) dp[i][0] = 0;
        
      for(int i = 1 ; i <= i1 ; i++){
         for(int j = 1 ; j <= i2 ; j++){
                if(text1[i-1] == text2[j-1]){
                     dp[i][j] =  1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
}
         
  int len = dp[i1][i2];
  int i = i1;
  int j = i2;

  int index = len - 1;
  string ans = "";

  while (i > 0 && j > 0) {
    if (text1[i - 1] == text2[j - 1]) {
      ans += text1[i-1];
      index--;
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
        ans += text1[i-1];
        i--;
    } else {
        ans += text2[j-1];
        j--;
    }
  }
  
  //Adding Remaing Characters - Only one of the below two while loops will run 
  
  while(i>0){
      ans += text1[i-1];
      i--;
  }
  while(j>0){
      ans += text2[j-1];
      j--;
  }

  reverse(ans.begin(),ans.end());
  
  SCS = ans;
  
  return len;
              
}

    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        string SCS ;
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
    
        int LenSCS = f(n1,n2,dp,str1,str2,SCS);
        
        return SCS;
        
    }
};