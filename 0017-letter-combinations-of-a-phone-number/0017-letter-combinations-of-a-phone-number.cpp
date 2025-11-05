class Solution {
   vector<string> mapper = {
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
    };
public:
    vector<string> combo(string p,string up){
        if(up.empty()){
            return {p};
        }

        vector<string> ans;
        string key = mapper[up[0]-'2'];
        for(auto &i:key){
            vector<string> temp = combo(p+i,up.substr(1));
            ans.insert(ans.end(),temp.begin(),temp.end());
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        return combo("",digits);
    }
};