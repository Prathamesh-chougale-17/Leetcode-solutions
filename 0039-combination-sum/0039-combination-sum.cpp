class Solution {
public:
    void back(vector<vector<int>> &sol,vector<int> &tmp,vector<int> &can,int j,int n,int t){
        if(t==0){
            sol.push_back(tmp);
            return;
        }
        if(t<0)return;
        for(int i=j;i<n;i++){
            tmp.push_back(can[i]);
            back(sol,tmp,can,i,n,t-can[i]);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& can, int t) {
        vector<vector<int>> sol;
        vector<int> tmp;
        int n = can.size();
        back(sol,tmp,can,0,n,t);
        return sol;
    }
};