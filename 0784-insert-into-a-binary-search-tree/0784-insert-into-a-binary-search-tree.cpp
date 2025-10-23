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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* head = root;
        TreeNode* Node = new TreeNode(val);
        while(1){
            if(head){
                    if(head->val<=val){
                        if(head->right){
                            head = head->right;
                        }else{
                            head->right = Node;
                            break;
                        }
                    }else{
                        if(head->left){
                            head = head->left;
                        }else{
                            head->left = Node;
                            break;
                        }
                    }
            }else{
                root = Node;
                break;
            }
        }
        return root;
    }
};