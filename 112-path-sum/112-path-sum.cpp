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
     void hasPathSumHelper(TreeNode* root,int targetSum,int contri,bool &res){
       
         //Base case and not a  valid base case
         if(!root){
             return;
         }
         
         //if reached the root node check for the contri value and answer the 
         if(!root->left && !root->right){
             contri += root->val;
             res = (targetSum == contri) ? true : res;
             return;
         }
        
        //Recursive soln
        hasPathSumHelper(root->left,targetSum,contri+root->val,res);
        if(res == true) return;
        hasPathSumHelper(root->right,targetSum,contri+root->val,res);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        bool res = false;
        hasPathSumHelper(root,targetSum,0,res);
        return res;
    }
};