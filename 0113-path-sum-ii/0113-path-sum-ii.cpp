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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)return {};
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,vector<int>>>> q;
        q.push({root,{root->val,{root->val}}});
        while(!q.empty()){
            TreeNode *tmp = q.front().first;
            int x = q.front().second.first;
            vector<int> z = q.front().second.second;
            q.pop();
            if(!tmp->left && !tmp->right){
                if(x == targetSum){
                    ans.push_back(z);
                }
                continue;
            }
            if(tmp->left){
                vector<int> tempz = z;
                tempz.push_back(tmp->left->val);
                q.push({tmp->left,{x+tmp->left->val,tempz}});
            }
            if(tmp->right){
                vector<int> tempr = z;
                tempr.push_back(tmp->right->val);
                q.push({tmp->right,{x+tmp->right->val,tempr}});
            }
        }
        return ans;
    }
};