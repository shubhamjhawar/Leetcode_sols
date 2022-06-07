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
    int f(TreeNode* root){
       
       //Base cases
       if(!root) return INT_MAX;
        
        
        //Base case
        if((!root->left) && (!root->right)){
            return 1;
        }
        
        
        
        //Recursive case
        return 1 + min(f(root->left),f(root->right));
        
    }
    int minDepth(TreeNode* root) {
        
        if(!root) return 0;
        
        return f(root);
    }
};