class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans{1},ls=0,rs=0;
        int temp = left;
        while(temp){
            ls++;
            temp>>=1;
        }
        cout<<ls<<endl;
        temp = right;
        while(temp){
            rs++;
            temp>>=1;
        }
            cout<<rs<<endl;
        if(ls!=rs)return 0;
        ans = right;
        for(int i=left;i<right;i++){
            ans&=i;
        }
        return ans;
    }
};