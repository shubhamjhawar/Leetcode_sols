class Solution {
public:
vector<vector<int>> nbrs = {{1,0} , {0,1} , {-1,0} , {0,-1} };
void dfs(vector<vector<int>>& board,vector<vector<bool>>& visited ,int i ,int j,int& answer){
        
        int m = board.size();
        int n = board[0].size();
    
        visited[i][j] = true;
        answer += board[i][j];
        
        for(auto& nbr : nbrs){
            
            int x = i + nbr[0];
            int y = j + nbr[1];
            
            
           if(x < 0 || y < 0 || x >= m || y >= n || visited[x][y] || board[x][y] == 0)                
                continue;
               
            
            dfs(board,visited,x,y,answer);          
    }
        
}

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        
        int n = grid.size();
        int m = grid[0].size(),res = 0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0 ; i < n ; i++){
            int answer;
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] != 0 && !visited[i][j]){
                    answer = 0;
                    dfs(grid,visited,i,j,answer);
                     res = max(answer,res);
                }
               
                
            }
        }
        
        return res;
 }
    
};
    