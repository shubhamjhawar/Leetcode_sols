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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*>st1;
        
        vector<int> res;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            
            res.push_back(root->val);
            
            if(root->left){
                st1.push(root->left);
            }
            
            if(root->right){
                st1.push(root->right);
            }
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};