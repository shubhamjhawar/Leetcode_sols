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
        
        int dx[] = {-1,0,1,0};
        int dy[] =  {0,1,0,-1};
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
            
            for(int i  = 0 ; i < 4 ; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if(newX >= 0 and newY >= 0 and newX < n and newY < m and grid[newX][newY] == 1){
                    grid[newX][newY] = 2;
                    q.push(node(newX,newY,time+1));
                }
            }
            
        }
        cout << cnt << " " << cntNot0 << endl;
         
        if(cnt == cntNot0) 
            return res;
        return -1;
        
        
    }
};