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
    //return the res and also calculate the height of the tree
    int f(TreeNode* root,int& res){
        
        //Base case
        if(!root){
            return 0;
            res = max(res,0);
        }
        
        //Recursive case
        int lh = 0,rh = 0;
        
        lh = f(root->left,res);
        rh = f(root->right,res);
        
        
        //Calculate teh max diamater till date as a whole
        res = max(lh+rh,res);
        //calculate the result as follows
        
        return 1 + max(lh,rh);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int res = 0;
        f(root,res);
        return res;
    }
};