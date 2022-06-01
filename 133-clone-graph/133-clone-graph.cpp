/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* start ,unordered_map<Node*,Node*>& m){
        m[start] = new Node(start->val);
        
        for(auto& nbrs : start->neighbors){
            if(m.find(nbrs) != m.end()){
                m[start]->neighbors.push_back(m[nbrs]);
            }
            else{
                dfs(nbrs,m);
                m[start]->neighbors.push_back(m[nbrs]);
            }
        }
        
    }
    
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        //stores a pointer to the node which is exactly the clone
        unordered_map<Node*,Node*> m;
        
        dfs(node,m);
        return  m[node];
    }
};