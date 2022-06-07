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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double> res;
        
        if(!root) return res;
        
        while(q.size() != 0){
            
            int n = q.size();
            double cum_sum = 0;
            for(int i = 0 ; i < n ; i++){
                
                TreeNode* t = q.front();
                q.pop();
                
                cum_sum += t->val;
                
                //Left node
                if(t->left) q.push(t->left);
                
                //right node
                if(t->right) q.push(t->right);
                   
            }
            // double ans = ;
            res.push_back((double)cum_sum/n);
        }
        return res;
    }
};