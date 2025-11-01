class Solution {
public:
    int clumsy(int n) {
        int op = 0;
        int temp = n;
        int sol = 0;
        for(int i = n-1;i>0;i--){
            if(op==0) temp*=i;
            else if(op==1) temp/=i;
            else if(op==2) temp+=i;
            else{
                sol+=temp;
                temp = -1*i;
            }
            op = (op+1)%4;
        }
        sol+=temp;
        return sol;
    }
};