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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root)   return root;
        queue<TreeNode*> q;
        q.push(root);
        int lev=0;
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*> nodes;
            for(int i=0;i<n;i++){
                TreeNode* cur=q.front();
                q.pop();
                nodes.push_back(cur);

                if(cur->left)   q.push(cur->left);
                if(cur->right)  q.push(cur->right);
            }

            if(lev%2==1){
                int l=0,r=nodes.size()-1;
                while(l<r){
                    swap(nodes[l++]->val,nodes[r--]->val);
                }
            }
            lev++;
        }
        return root;
    }
};