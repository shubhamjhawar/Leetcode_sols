class Solution {
public:

 
    void dfs(unordered_map<char,vector<char>>& graph, unordered_map<char,int>& visited,char start,int label){
        
        visited[start] = label;
        
        for(auto& nbr: graph[start]){
            if(visited.find(nbr) == visited.end()){
                dfs(graph,visited,nbr,label);
            }
        }
    }
        
    
    bool equationsPossible(vector<string>& equations) {
        
        unordered_map<char,vector<char>> graph;
        unordered_map<char,int> visited;
        
for(auto& eqn : equations){
            
     if(eqn[0] == eqn[3]){
        if(eqn[1] == '!')
        {
            return false;     
        } 
    
         continue;
      }
          
            
       if(eqn[1] == '='){
                graph[eqn[0]].push_back(eqn[3]);
                graph[eqn[3]].push_back(eqn[0]);
        }
            
}
            
        
       int label = 0;
    
        for(auto& node : graph){
            if(visited.find(node.first) == visited.end()){
                dfs(graph,visited,node.first,label);
                ++label;
            }
        }
        
         for(auto& eqn : equations){
            if(eqn[1] == '!'){
               if(visited.find(eqn[0]) != visited.end()  
                  && visited.find(eqn[3]) != visited.end()
                  && visited[eqn[0]] == visited[eqn[3]])
                 {
                   return false;
                 }
            }
        }
        
        return true;
        
           
    }
};