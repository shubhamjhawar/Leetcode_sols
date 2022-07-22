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
    bool f(TreeNode* root,int val){
        //Base case
        if(!root){
            return true;
        }
        
        if(root->left != NULL and root->left->val != val){
            return false;
        }
         if(root->right != NULL and root->right->val != val){
            return false;
        }
        
        bool l = true ,r = true;
        //Left Subtree
        if(root->left)
            l = f(root->left,val);
        
        //Right Subtree
        if(root->right)
            r = f(root->right,val);
        
        return l && r;
        
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        return f(root,root->val);
    }
};