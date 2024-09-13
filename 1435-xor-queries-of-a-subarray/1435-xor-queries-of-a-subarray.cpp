class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans(queries.size());
        for(int i=1;i<n;i++) arr[i]^=arr[i-1];
        arr.push_back(0);
        for(int i=0;i<queries.size();i++)
            ans[i]=arr[queries[i][1]]^arr[(queries[i][0]-1)>-1?(queries[i][0]-1):n];
        return ans;
    }
};