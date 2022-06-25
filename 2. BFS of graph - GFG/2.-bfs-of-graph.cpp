// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
 void bfs(int node,vector<int> adj[],vector<int>& res,vector<int>& vis){
  vis[node] = 1;
  queue<int> q;
  q.push(node);

 while(q.size()){
    int node  = q.front();
    q.pop();
     
    res.push_back(node);

    for(auto it : adj[node]){
      if(vis[it] == 0){
          vis[it] = 1;
          q.push(it);
      }
    }
  }
  
  
}
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int n = V;
        vector<int> res;
        vector<int>vis(n,0);
       
        bfs(0,adj,res,vis);
         
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends