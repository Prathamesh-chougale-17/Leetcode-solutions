class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> al;
        int ans = words.size();
        for(auto &i:allowed)al[i]++;
        for(auto &i:words){
            for(auto &j:i){
                if(al[j]==0) {
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};