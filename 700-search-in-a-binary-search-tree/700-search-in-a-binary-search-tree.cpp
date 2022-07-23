class Solution {
public:
  TreeNode* helper(TreeNode* root,int val){
      if(!root){
          return  NULL;
      }
      
      if(root->val == val){
          return root;
      }
      
      if(root->val > val){
         return  helper(root->left,val);
      }
         
       return helper(root->right,val);
    
  }
  TreeNode* searchBST(TreeNode* root, int val) {
    
     return helper(root,val);
  }
};