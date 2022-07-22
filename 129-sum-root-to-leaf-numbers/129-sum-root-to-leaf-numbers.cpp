
class Solution {
public:
    void SumNumbersHelper(TreeNode* root,int& res,string contri){
        
        if(!root){
            return;
        }
        
        
        //Base Case
        if(!root->left && !root->right){
            string s2 = to_string(root->val);
            res += stoi(contri + s2);
            return;
        }
        
        
        //Recursive case
        string s1 = to_string(root->val);
        SumNumbersHelper(root->left,res,contri+s1);
        SumNumbersHelper(root->right,res,contri+s1);
        
     
    }
    int sumNumbers(TreeNode* root) {
        int res = 0;
        string contri = "";
        SumNumbersHelper(root,res,contri);
        
        return res;
    }
};