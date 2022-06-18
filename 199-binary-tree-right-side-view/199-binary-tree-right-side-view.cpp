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
    void f(TreeNode* root,vector<int>& res,int level){
      if(!root){
          return;
      }  
        
      if(res.size() == level){
          res.push_back(root->val);
      }  
      
      //Covering the right boundary as a whole
      f(root->right,res,level+1);
        
      //Cover the left boundary as well
      f(root->left,res,level+1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        f(root,res,0);
        return res;
    }
};