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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,long long>> q;
        int maxi = 1;
        q.push({root,0});
        while(!q.empty()){
            int s = q.size();
            int minn = q.front().second;
            for(int i=0;i<s;i++){
                TreeNode* tmp = q.front().first;
                long long x = q.front().second-minn;
                q.pop();
                if(tmp->left)q.push({tmp->left,2*x});
                if(tmp->right)q.push({tmp->right,2*x+1});
            }
            if(!q.empty())
                maxi = max(int(q.back().second-q.front().second+1),maxi);
        }
        return maxi;
    }
};

/*
                            0
                        0       1
                    1   2       3    4
                1   2   3  4 5  6    7  8
            1       4       6       4       1


                            0
                        -1      1
                    -2      2       2
                -4      -1      1       4
            -4      
*/