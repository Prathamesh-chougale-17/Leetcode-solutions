class Solution {
public:
    int minAddToMakeValid(string &s) {
        int x=0;
        int sol=0;
        for(auto &i:s){
            if(i=='('){
                if(x<0){
                    sol+=abs(x);x=0;
                }
                x++;
            }
            else x--;
        }
        return sol+abs(x);
    }
};