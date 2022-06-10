class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<bool>& visited,int start){
        visited[start] = true;
        for(auto& x : rooms[start]){
            if(!visited[x]){
                dfs(rooms,visited,x);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<bool>visited(n,false);
        //visited[0] = true;
        for(int i = 0 ; i < n ; i++){
            dfs(rooms,visited,0);
            //cout << visited[i] << endl;
        }
        
        return n == count(visited.begin(),visited.end(),true);
    }
};