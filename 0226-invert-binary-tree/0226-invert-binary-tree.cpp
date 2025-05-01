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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
       queue<TreeNode*> q;
       q.push(root);
        while(!q.empty()){
        TreeNode* p = q.front();
            q.pop();
            TreeNode* temp = p->right;
            if(p->right){
                q.push(p->right);
            }
            if(p->left){
                q.push(p->left);
            }
            p->right = p->left;
            p->left = temp;
            p = p->left;
        }
        return root;
    }
};