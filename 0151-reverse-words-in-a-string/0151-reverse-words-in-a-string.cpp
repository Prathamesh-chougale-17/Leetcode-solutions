class Solution {
public:
    string reverseWords(string &s) {
        vector<string> v;
        string temp="",ans="";
        for(auto &i:s){
            if(i!=' '){
                temp.push_back(i);
            }else{
                if(temp!="")
                    v.push_back(temp);
                temp="";
            }
        }
        if(temp!="")v.push_back(temp);
        for(int i=v.size()-1;i>=0;i--){
            ans+=v[i]+" ";
        }
        ans.pop_back();
        return ans;
    }
};