class Solution {
public:
   vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> um;
        string temp="";
        for(auto &i:strs){
            temp=i;
            sort(i.begin(),i.end());
            um[i].push_back(temp);
        }
        for(auto &i:um){
            ans.push_back(i.second);
        }
        return ans;
    }
};