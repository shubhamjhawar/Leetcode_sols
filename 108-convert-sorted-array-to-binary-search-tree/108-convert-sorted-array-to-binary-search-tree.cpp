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
    TreeNode* constructTree(vector<int>& nums,int left , int right){
        
        if(left > right){
            return NULL;
        }
        
        int mid = left + (right - left + 1)/2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = constructTree(nums,left,mid-1);
        curr->right = constructTree(nums,mid+1,right);
        
        return curr;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return constructTree(nums,0,nums.size()-1);
    }
    
    
    //Power of Recursion
    //    0  1    2    3   4  5  6 
    // [-10 ,-5 ,-3 ,0 , 5, 8, 9]   //indices
    //Calculate the middle element
    // 0 + (7 - 1)/2; = 3
    
         
    
};