/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool lcaHelper(TreeNode* root,TreeNode* p , TreeNode* q ,TreeNode** res){
        
        if(!root){
            return false;
        }
        bool l1 = lcaHelper(root->left,p,q,res);
        bool l2 = lcaHelper(root->right,p,q,res);
        
        if(!(*res)){
            if((l1 && l2) || ((root == p || root == q) && (l1 || l2))){
                *res = root;
                return true;
            }
        }
        
        return l1 || l2 || (root == p) || (root == q) ;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = NULL;
        
        lcaHelper(root,p,q,&res);
        
        return (res);
    }
};