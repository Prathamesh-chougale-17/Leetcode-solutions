class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ps,pt;
        for(auto &i:s){
            if(i=='#' && ps.size()>0){
                ps.pop_back();
            }else if(i!='#'){
                ps.push_back(i);
            }
        }
        
        for(auto &i:t){
            if(i=='#' && pt.size()>0){
                pt.pop_back();
            }else if(i!='#'){
                pt.push_back(i);
            }
        }

        return ps==pt;
    }
};