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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        queue<pair<TreeNode*,int>> q;
        vector<int> ans;
        q.push({root,0});
        while(!q.empty()){
            TreeNode *tmp = q.front().first;
            int val = q.front().second;
            q.pop();
            if(ans.size()<(val+1))ans.push_back(tmp->val);
            else{
                ans[val] = tmp->val;
            }
            if(tmp->left)q.push({tmp->left,val+1});
            if(tmp->right)q.push({tmp->right,val+1});
        }
        return ans;
    }
};