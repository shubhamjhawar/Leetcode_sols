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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(!root) return res;
        q.push(root);
        
        while(q.size()){
            int n = q.size();
            res.push_back({});
            for(int i = 0 ; i < n ; i++){
                TreeNode* t = q.front();
                q.pop();
                
                
                //Push to the nextlevel in the queue
                if(t->left){
                    q.push(t->left);
                }
                
                
                //Push the  next level which is right in the queue
                if(t->right){
                    q.push(t->right);
                }
                
                
                res[res.size()-1].push_back(t->val);
                
     
            }
        }
        
        
        reverse(res.begin(),res.end());
        return res;
        
    }
};