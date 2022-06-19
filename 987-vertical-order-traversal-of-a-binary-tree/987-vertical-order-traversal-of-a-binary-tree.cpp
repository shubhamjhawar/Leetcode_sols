/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue <pair<TreeNode *,pair<int,int >>> q;
        map<int,map<int,multiset<int>>>  nodes;
        q.push({root,make_pair(0,0)});
        while(q.size()){
            auto p = q.front();
            q.pop();
            TreeNode* temp = p.first;
            int x = p.second.first;
            int y = p.second.second;
            
            //Add it into data structure
            nodes[x][y].insert(temp->val);
            
            if(temp->left){
                q.push({temp->left,make_pair(x-1,y+1)});
            }
            
            if(temp->right){
                q.push({temp->right,make_pair(x+1,y+1)});
            }
        }
        vector<vector<int>> ans;
        
        for(auto p : nodes){
            vector<int> col;
            
            for(auto q : p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};