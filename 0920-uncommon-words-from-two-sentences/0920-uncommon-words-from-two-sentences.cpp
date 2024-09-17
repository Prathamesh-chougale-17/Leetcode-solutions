class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> vs;
        vector<string> ans;
        string temp;
        for(auto &i:s1){
            if(i!=' ')temp.push_back(i);
            if(i==' ' && temp!=""){
                vs.push_back(temp);
                temp="";
            }
        }
        if(temp!=""){
            vs.push_back(temp);
            temp="";
        }
        for(auto &i:s2){
            if(i!=' ')temp.push_back(i);
            if(i==' ' && temp!=""){
                vs.push_back(temp);
                temp="";
            }
        }
        if(temp!="")vs.push_back(temp);
        unordered_map<string,int> um;
        for(auto &i:vs)um[i]++;
        for(auto &i:um){
            if(i.second==1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};