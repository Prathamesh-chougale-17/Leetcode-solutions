class Solution {
public:
    static bool cmp(pair<char,int> &a,pair<char,int> &b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        vector<pair<char,int>> vp;
        unordered_map<char,int> um;
        for(auto &i:s){
            um[i]++;
        }
        for(auto &i:um){
            vp.push_back(i);
        }
        sort(vp.begin(),vp.end(),cmp);
        string ans;
        for(auto &i:vp){
            for(int j=0;j<i.second;j++){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};