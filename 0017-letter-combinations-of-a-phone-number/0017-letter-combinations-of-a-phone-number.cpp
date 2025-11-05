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
        for(int j=0;j<key.size();j++){
            vector<string> temp = combo(p+key[j],up.substr(1));
            ans.insert(ans.end(),temp.begin(),temp.end());
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        return combo("",digits);
    }
};