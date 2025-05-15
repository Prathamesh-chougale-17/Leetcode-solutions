class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> um,f;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(um[s[i]] && um[s[i]]!=t[i]){
                return false;
            }
            um[s[i]]=t[i];
        }
        for(auto &i:um){
            if(f[i.second]>0)return false;
            f[i.second]++;
        }
        return true;
    }
};