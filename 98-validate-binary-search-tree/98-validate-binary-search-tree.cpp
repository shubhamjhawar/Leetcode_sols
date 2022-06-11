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
    bool isValidBSTHelper(TreeNode* root,long &max_elt,long &min_elt){
        
        //Base case
        if(!root){
            min_elt = LONG_MAX;
            max_elt = LONG_MIN;
            return true;
        }
       
        //Recursive case
        bool ans_l = false,ans_r = false;
        long min_l ,min_r,max_r,max_l;
        
        ans_l = isValidBSTHelper(root->left,max_l,min_l);
        ans_r = isValidBSTHelper(root->right,max_r,min_r);
        
        
        min_elt = min(long(root->val),min(min_l,min_r));
        max_elt = max(long(root->val),max(max_l,max_r));
        
        return ans_l && ans_r && (root->val > max_l && root->val < min_r);
        
    }
    bool isValidBST(TreeNode* root) {
       long min_elt = LONG_MAX;
       long max_elt = LONG_MIN;
        
       return isValidBSTHelper(root,min_elt,max_elt);
        
        
    }
};