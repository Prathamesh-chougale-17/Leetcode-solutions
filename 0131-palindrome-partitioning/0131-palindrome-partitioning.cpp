using vvs = vector<vector<string>>;
using vs = vector<string>;
class Solution {
public:
    bool ifpali(string &s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }
    void back(string &s,int ind,vvs &ans,int n,vs &sol){
        if(ind==n){
            ans.push_back(sol);
            return;
        }
        for(int i=ind;i<n;i++){
            if(ifpali(s,ind,i)){
                sol.push_back(s.substr(ind,i-ind+1));
                back(s,i+1,ans,n,sol);
                sol.pop_back();
            }
        }
    }
    vvs partition(string s) {
        vvs ans;
        vs sol;
        int n = s.size();
        back(s,0,ans,n,sol);
        return ans;
    }
};