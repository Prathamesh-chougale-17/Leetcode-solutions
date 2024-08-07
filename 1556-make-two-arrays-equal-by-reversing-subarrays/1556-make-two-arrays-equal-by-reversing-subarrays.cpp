class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mt,ma;
        for(auto &i:target){
            mt[i]++;
        }
        for(auto &j:arr){
            ma[j]++;
        }
        for(auto &i:target){
            if(ma[i]!=mt[i]) return false;
        }
        return true;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();