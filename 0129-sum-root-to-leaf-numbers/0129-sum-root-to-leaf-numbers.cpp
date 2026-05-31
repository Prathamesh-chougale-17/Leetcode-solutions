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
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        int sol = 0;
        queue<pair<TreeNode*,string>>q;
        q.push({root,to_string(root->val)});
        while(!q.empty()){
            TreeNode *tmp = q.front().first;
            string s = q.front().second;
            q.pop();
            if(!tmp->left && !tmp->right) sol+=stoi(s);
            if(tmp->left) q.push({tmp->left,s+to_string(tmp->left->val)});
            if(tmp->right) q.push({tmp->right,s+to_string(tmp->right->val)});
        }
        return sol;
    }
};