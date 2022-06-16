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
    //Returns true if tree is balanced and also return the height of the subtree
    bool isBalancedHelper(TreeNode* root,int& height){
        
        //Base step
        if(!root){
            height = 0;
            return true;
        }
        
        
        
        //Recursive step
        bool ans_r = true, ans_l = true;
        int height_l = -1,height_r = -1;
        
        //Get the height of left subtree
        ans_l = isBalancedHelper(root->left,height_l);
        
        //Get the height of the right subtree
        ans_r = isBalancedHelper(root->right,height_r);
        
        //Compute the height
        height = 1 + max(height_l,height_r);
        
        
        return ans_l && ans_r && abs(height_l - height_r) <= 1;
        
        
        
    }
    bool isBalanced(TreeNode* root) {
        
        int height = 0;
        
        return isBalancedHelper(root,height);
    }
};