class Solution {
public:
    int myAtoi(string s) {
        long num = 0;
        bool isnum = false;
        int sign = 1;
        for(auto &i:s){
            if(!isnum && (i==' ')){
                continue;
            }
            else if(!isnum && i=='-'){
                isnum=true;
                sign = -1;
            }
            else if(!isnum && i=='+'){
                isnum=true;
                sign = 1;
            }
            else if(i<='9' && i>='0'){
                isnum=true;
                num = num*10 + sign*(i-'0');
                if(num>INT_MAX)return INT_MAX;
                if(num<INT_MIN)return INT_MIN;
            }else {
                break;
            }
        }
        return (int)num;
    }
};