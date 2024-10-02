class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> m;
        int z=0;
        for(auto &i:arr)m[i]=1;
        for(auto &i:m) i.second = ++z;
        for(auto &i:arr)i=m[i];
        return arr;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();