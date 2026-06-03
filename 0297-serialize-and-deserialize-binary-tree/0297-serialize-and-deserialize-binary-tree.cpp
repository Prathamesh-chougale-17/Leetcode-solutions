/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        string s;
        queue<TreeNode*> q;
        q.push(root);
        s+=to_string(root->val)+",";
        while(!q.empty()){
            TreeNode *tmp = q.front();
            q.pop();
            if(tmp->left){
                q.push(tmp->left);
                s+=to_string(tmp->left->val)+",";
            }else{
                s+="#,";
            }
            if(tmp->right) {
                q.push(tmp->right);
                s+=to_string(tmp->right->val)+",";
            }else{
                s+="#,";
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(!data.size())return nullptr;
        stringstream s(data);
        cout<<data;
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            getline(s,str,',');
            if(str!="#"){
                tmp->left = new TreeNode(stoi(str));
                q.push(tmp->left);
            }
            getline(s,str,',');
            if(str!="#"){
                tmp->right = new TreeNode(stoi(str));
                q.push(tmp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));