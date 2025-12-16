class Solution {
public:
    void back(int n,int i,int j,string s,vector<string> &ans){
        if(j==n && i==n){
            ans.push_back(s);
            return;
        }
        if(i<n)back(n,i+1,j,s+"(",ans);
        if(j<i)back(n,i,j+1,s+")",ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        back(n,0,0,"",ans);
        return ans;
    }
};