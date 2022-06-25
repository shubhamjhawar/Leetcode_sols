// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
   void dfs(int node,vector<int> adj[],vector<int>& visited,vector<int>& res){
       visited[node] = true;
       res.push_back(node);
       
       for(auto& elt : adj[node]){
           if(!visited[elt]){
               dfs(elt,adj,visited,res);
           }
       }
   }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>visited(V,false);
        vector<int> res;
        dfs(0,adj,visited,res);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends