class Solution {
public:
    int min(int a,int b){
        return a>b?b:a;
    }
    string longestCommonPrefix(vector<string>& strs) {
        char temp;
        string ans;
        int minsi{INT_MAX};
        for(auto &i:strs){
            minsi = min(minsi,i.size());
        }
        for(int i=0;i<minsi;i++){
            temp = strs[0][i];
            for(auto &j:strs){
                if(j[i]!=temp) return ans;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};