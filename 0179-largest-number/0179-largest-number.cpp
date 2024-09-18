class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ts;
        for(auto &i:nums)ts.push_back(to_string(i));
        sort(ts.begin(),ts.end(),[](string &a,string &b){
            return (b+a)<(a+b);
        });
        if(ts[0]=="0") return "0";
        string ans;
        for(auto &i:ts){
            ans = ans + i;
        }
        return ans;
    }
};