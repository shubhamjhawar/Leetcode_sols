struct node{
    int x,y,time;
    node(int _x,int _y,int _time){
        x = _x;
        y = _y;
        time = _time;
    } 
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cntNot0 = 0;
        queue<node> q;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push(node(i,j,0));
                }
                if(grid[i][j] != 0){
                    cntNot0++;
                }
            }
        }
        
        vector<vector<int>> nbrs = {{1,0} , {0,1} , {-1,0} , {0,-1} };
        int res = 0;
        int cnt = 0;
        while(q.size()){
            node elt = q.front();
            q.pop();
            cnt++;
            int x = elt.x;
            int y = elt.y;
            int time = elt.time;
            
            res = max(res,time);
            
             for(auto& nbr: nbrs){
                int _x = x + nbr[0];
                int _y = y + nbr[1];
                 
                if(_x >= 0 and _y >= 0 and _x < n and _y < m and grid[_x][_y] == 1){
                    grid[_x][_y] = 2;
                    q.push(node(_x,_y,time+1)); 
                }
                 
              }
          }
            
         if(cnt == cntNot0) 
            return res;
        return -1;
        
        
    }
};