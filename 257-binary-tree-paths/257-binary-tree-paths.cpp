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
    void f(TreeNode* root,vector<string>& res,string contri){
        if(!root) return;
        
         if(!root->left && !root->right ){
           contri += to_string(root->val);
           res.push_back(contri);
           return;
        }
    
        string s = to_string(root->val) + "->";
        f(root->left,res,contri+s);
        f(root->right,res,contri+s);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string contri = "";
        f(root,res,contri);
        
        return res;
    }
};

/* void f(TreeNode* root,string& res,string contri){
        if(!root) return;
        
        
        if(!root->left && !root->right ){
            char i = 'a' + root->val;
            contri += i;
            reverse(contri.begin(),contri.end());
            if(res.size() == 0){
                res = contri;
            }
            else{
                res = min(contri,res);
            }
            
        }
    
        char c = 'a' + root->val;
        f(root->left,res,contri+c);
        f(root->right,res,contri+c);
    }
    string smallestFromLeaf(TreeNode* root) {
        string res = "";
        string contri = "";
        f(root,res,contri);
        
        return res;
    }*/