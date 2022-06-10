// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    public:
     vector<vector<int>> nbrs = { {1 ,0} , {0, 1} , {-1, 0} , {0, -1} ,{-1, -1} ,{1 , 1} ,{-1,1 } , { 1, -1} };
    void dfs(vector<vector<char>>& board,vector<vector<bool>>& visited ,int i ,int j){
        int n = board.size();
        int m = board[0].size();
        visited[i][j] = true;
        
        for(auto& nbr : nbrs){
            int x = i + nbr[0];
            int y = j + nbr[1];
            
            if(x < 0 || y < 0 || x >= n || y >= m || visited[x][y] || board[i][j] == '0')
                     continue;   
             
            dfs(board,visited,x,y);
        }
        
    } 
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] != '0' && !visited[i][j]){
                    dfs(grid,visited,i,j);
                    res++;
                }
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends