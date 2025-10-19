class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string sol;
        int i = 0, j = 0, ws1 = word1.size(), ws2 = word2.size();
        while(i<ws1 && j<ws2){
            if(sol.size()%2==0){
                sol.push_back(word1[i++]);
            }else{
                sol.push_back(word2[j++]);
            }
        }
        while(i<ws1){
            sol.push_back(word1[i++]);
        }
        while(j<ws2){
            sol.push_back(word2[j++]);
        }
        return sol;
    }
};