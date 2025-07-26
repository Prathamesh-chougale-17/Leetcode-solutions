class Solution {
public:
    string countAndSay(int n) {
        string s = "1",sol=s;
        for(int i=1;i<n;i++){
            char present = s[0];
            int c = 0;
            int m = s.size();
            sol = "";
            for(int j = 0;j<m;j++){
                if(present == s[j]){
                    c++;
                }else{
                    sol+=(to_string(c) + present);
                    present = s[j];
                    c=1;
                }
            }
            sol+=(to_string(c)+present);
            cout<<sol<<endl;
            s = sol;
        }
        return sol;
    }
};