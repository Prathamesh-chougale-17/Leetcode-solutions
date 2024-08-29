class Solution {
public:
    string largestOddNumber(string num) {
        int ans = 0;
        for(int i=0;i<num.size();i++){
            if(num[i]&1) ans=i+1;
        }
        cout<<ans;
        return num.substr(0,ans);
    }
};