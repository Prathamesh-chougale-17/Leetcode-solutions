class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int t=0,r=m[0].size()-1,l=0,b=m.size()-1;
        vector<int> ans;
        while(t<=b && r>=l){
            for(int i=l;i<=r;i++){
                ans.push_back(m[t][i]);
            }
            t++;
            for(int i=t;i<=b;i++){
                ans.push_back(m[i][r]);
            }
            r--;
            if(t<=b)for(int i=r;i>=l;i--)ans.push_back(m[b][i]);
            b--;
            if(l<=r)for(int i=b;i>=t;i--)ans.push_back(m[i][l]);
            l++;
        }
        return ans;
    }
};