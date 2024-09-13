class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans(queries.size());
        vector<int> pre(n+1);
        int xori = 0;
        for(int i=0;i<n;i++){
            xori^=arr[i];
            pre[i]=xori;
        }
        for(int i=0;i<queries.size();i++){
            ans[i]=pre[queries[i][1]]^pre[(queries[i][0]-1)>-1?(queries[i][0]-1):n];
        }
        return ans;
    }
};