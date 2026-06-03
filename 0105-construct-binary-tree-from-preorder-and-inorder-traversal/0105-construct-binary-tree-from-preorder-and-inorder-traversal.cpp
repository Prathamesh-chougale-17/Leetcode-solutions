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
    TreeNode* build(vector<int>& preorder,int sp,int ep,int si,int ei,unordered_map<int,int> &um){
        if(sp>ep || si>ei)return nullptr;
        TreeNode *root = new TreeNode(preorder[sp]);
        int ind = um[preorder[sp]];
        int s = ind-si;
        root->left = build(preorder,sp+1,sp+s,si,ind-1,um);
        root->right = build(preorder,sp+s+1,ep,ind+1,ei,um);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> um;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            um[inorder[i]]=i;
        }
        return build(preorder,0,n-1,0,n-1,um);

    }
};