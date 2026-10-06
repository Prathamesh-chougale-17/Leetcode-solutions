class Solution {
public:
    bool checkValidString(string &s) {
        int x=0,y=0,n = s.size();
        // if(s.size()%2)return false;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='('){
                x++;
                if(y<x)return false;
            }else if(s[i]==')'){
                x--;
            }else{
                y++;
            }
        }
        x=0,y=0;
        for(auto &i:s){
            if(i=='('){
                x++;
            }else if(i==')'){
                x--;
                if((x)<(-1*y))return false;
            }else{
                y++;
            }
        }
        return x<=y;
    }
};