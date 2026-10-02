class Solution {
public:
    void back(vector<string> &sol,string tmp,int i,int j,int n){
        if(j==n){
            sol.push_back(tmp);
            return;
        }
        if(i<n)back(sol,tmp+'(',i+1,j,n);
        if(j<i)back(sol,tmp+')',i,j+1,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        back(sol,"",0,0,n);
        return sol;
    }
};