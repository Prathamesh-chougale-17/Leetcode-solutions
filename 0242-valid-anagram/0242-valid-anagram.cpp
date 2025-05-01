class Solution {
public:
    bool isAnagram(string s, string t) {
        int ss=s.size(),ts=t.size();
        if(ss!=ts)return false;
        unordered_map<char,int> sm;
        for(int i=0;i<ss;i++){
            sm[s[i]]+=1;
            sm[t[i]]-=1;
        }
        for(auto &i:s){
            if(sm[i]!=0)return false;
        }
        return true;
    }
};