class Solution {
public:
    string digitSum(string s, int k) {
        // string sol;
        // for(int i=0;i<k;i++){
        //     sol.push_back('0');
        // }
        while(s.size()>k){
            string x;
            for(int i=0;i<s.size();i+=k){
                int z = 0;
                for(int j=i;j<i+k && j<s.size();j++){
                    z+=(s[j]-'0');
                }
                x+=to_string(z);
            }
            s = x;
        }
        return s;
    }
};