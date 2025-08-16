class Solution {
public:
    int maximum69Number (int num) {
        int temp = num,n = 0,s = -1,z = 1;
        while(temp){
            if(temp%10==6){
                s=n;
            }
            n++;
            temp/=10;
        }
        for(int i=0;i<s;i++){
            z*=10;
        }
        if(s>=0)return num + 3*z;
        return num;
    }
};