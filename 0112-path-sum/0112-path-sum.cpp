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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        queue<pair<TreeNode*,int>> q;
        q.push({root,root->val});
        while(!q.empty()){
            TreeNode* tmp = q.front().first;
            int x = q.front().second;
            q.pop();
            if(!tmp->left && !tmp->right){
                if(x == targetSum)return true;
                continue;
            }
            if(tmp->left)q.push({tmp->left,x+tmp->left->val});
            if(tmp->right)q.push({tmp->right,x+tmp->right->val});
        }
        return false;
    }
};