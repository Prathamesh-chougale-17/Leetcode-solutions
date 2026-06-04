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
    int mini = INT_MAX,prev = INT_MAX;
public:
    void inorder(TreeNode* root){
        if(!root)return ;
        inorder(root->left);
        mini = min(mini,abs(prev-root->val));
        prev = root->val;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        if(!root)return INT_MAX;
        inorder(root);
        return mini;
    }
};