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
void pathSumHelper(TreeNode* root ,int targetSum,vector<int>& contri,vector<vector<int>>& res){
        
    //Not a case
    if(!root) return;
    
    //base condition
    if(!root->left && !root->right){
        targetSum = targetSum - root->val;
        contri.push_back(root->val);
        if(targetSum == 0){
            res.push_back(contri);
        }
        contri.pop_back();
        return;
    }
   
    
    //recursive case
    //Recursive 
        contri.push_back(root->val);
        pathSumHelper(root->left,targetSum-root->val,contri,res);
    
        pathSumHelper(root->right,targetSum-root->val,contri,res);
        contri.pop_back();

}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> contri;
        pathSumHelper(root,targetSum,contri,res);
        
        return res;
        
    }
};