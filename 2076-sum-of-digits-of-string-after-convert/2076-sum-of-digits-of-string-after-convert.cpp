class Solution {
public:
    int getLucky(string s, int k) {
        int ans=0;
        string num;
        for(auto &i:s){
            num+=(to_string(i-'a'+1));
        }
        cout<<num;
       
        while(k--){
            ans=0;
            for(auto &i:num) ans+=i-'0';
            num=to_string(ans);
        }
        return ans;
    }
};