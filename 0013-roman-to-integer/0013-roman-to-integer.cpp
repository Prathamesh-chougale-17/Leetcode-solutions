class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> um = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
       
        int ans = um[s[0]], n = s.size();
        for(int i=1;i<n;i++){
            // if(um[s[i]]>um[s[i-1]]){
            //     ans += um[s[i]] - 2*um[s[i-1]];
            // }else{
            //     ans +=um[s[i]];
            // }
            ans += (um[s[i]] > um[s[i-1]]) ? um[s[i]] - 2 * um[s[i-1]] : um[s[i]];
        }
        return ans;
    }
};