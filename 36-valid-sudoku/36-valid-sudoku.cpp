class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>>rows(9);
        vector<unordered_set<char>>column(9);
        vector<unordered_set<char>>block(9);
        
        
        for(int i = 0 ;i < 9 ; i++){
            for(int j = 0 ;  j < 9 ; j++){
                
              if(board[i][j] == '.'){
                  continue;
              }  
              
             char curr = board[i][j];
              
              if(rows[i].count(board[i][j]) || column[j].count(board[i][j]) || block[(i/3)*3 + j/3].count(board[i][j])){
                  return false;
              }
                
             rows[i].insert(curr);
             column[j].insert(curr);
             block[(i/3)*3 + j/3].insert(curr);
                
            }
            
        }
        
        
        return true;
    }
};