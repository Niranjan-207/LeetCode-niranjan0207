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
    TreeNode* solve(TreeNode* root){
        if(!root)   return nullptr;
        TreeNode* le=solve(root->left);
        TreeNode* ri=solve(root->right);
        
        root->left=ri;
        root->right=le;
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(!root)   return root;
        return solve(root);
    }
};