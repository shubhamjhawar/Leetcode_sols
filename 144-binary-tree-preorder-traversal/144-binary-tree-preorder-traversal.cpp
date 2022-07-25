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
    vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    st.push(root);
    if(!root) return res;
    while(!st.empty()){
        TreeNode* t = st.top();
        st.pop();
        res.push_back(t->val);
        
        
        //push the right subtree first
        //as the stack works in this fashion of LIFO
        if(t->right){
          st.push(t->right);
        }
        
        //push the left subtree if this exist and 
        //the stack and remove whenever ypu want
        if(t->left){
            st.push(t->left);
        }
    }
    return res;
        
    }
};