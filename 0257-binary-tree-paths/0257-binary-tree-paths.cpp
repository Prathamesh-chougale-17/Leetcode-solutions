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
    vector<string> binaryTreePaths(TreeNode* root) {
        queue<pair<TreeNode*,string>> q;
        q.push({root,to_string(root->val)});
        vector<string> ans;
        while(!q.empty()){
            TreeNode *tmp = q.front().first;
            string s = q.front().second;
            q.pop();
            if(!tmp->right && !tmp->left){
                ans.push_back(s);
                continue;
            }
            if(tmp->left)q.push({tmp->left,s+"->"+to_string(tmp->left->val)});
            if(tmp->right)q.push({tmp->right,s+"->"+to_string(tmp->right->val)});
        }
        return ans;
    }
};