class Solution {
public:
vector<vector<int>> nbrs = {{0,1},{1,0},{-1,0},{0,-1}};
void DFS(vector<vector<int>>& board,vector<vector<bool>>& visited ,int i ,int j){
        
        
        int m = board.size();
        int n = board[0].size();
        visited[i][j] = true;
        
        for(auto& nbr : nbrs){
            
            int x = i + nbr[0];
            int y = j + nbr[1];
            
            
           if(  x < 0 || y < 0 || x >= m || y >= n || visited[x][y] || board[x][y] == 0)                
                continue;
               
            
            
            DFS(board,visited,x,y);          
    }
        
}
    
int numEnclaves(vector<vector<int>>& grid) {
              
        // return board;
        int m = grid.size();
        int n = grid[0].size(),i,j;
        
        vector<vector<bool>> visited (m,vector<bool>(n,false));
            
        
        //Moving over first and last column   
     for( i=0; i<m; i++) {
         if(grid[i][0] == 1)
             DFS(grid,visited,i,0);
         if(grid[i][n-1] == 1)
             DFS(grid, visited,i,n-1);
     }
        
     //Moving over left and the right columns
        
     for( j=0; j<n; j++) {
         if(grid[0][j] == 1)
             DFS(grid,visited,0,j);
         if(grid[m-1][j] == 1)
             DFS(grid,visited,m-1,j);
     }

        int count = 0;
        
        for(i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(!visited[i][j] && grid[i][j] == 1)
                    count++;
                
                }
            }
        
     
        return count;
        }
};