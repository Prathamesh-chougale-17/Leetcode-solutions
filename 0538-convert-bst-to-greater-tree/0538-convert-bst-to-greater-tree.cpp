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
    int n = 0;
public:
    void reverseInorder(TreeNode* root){
        if(!root)return;
        reverseInorder(root->right);
        n+=root->val;
        root->val = n;
        reverseInorder(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        reverseInorder(root);
        return root;        
    }
};