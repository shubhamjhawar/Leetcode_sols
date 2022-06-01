class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<bool>&visited,int index){
        int n = isConnected.size();
        visited[index] = true;
        
        for(int i = 0 ; i < n ; i++){
            if(isConnected[index][i] == 1 and !visited[i]){
                dfs(isConnected,visited,i);
            }
            
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited(n,false);
        
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                cnt++;
                dfs(isConnected,visited,i);
            }
        }
        
        return cnt;
    }
};