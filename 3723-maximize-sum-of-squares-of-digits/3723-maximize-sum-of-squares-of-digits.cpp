class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num)return "";
        string sol;
        int t9 = sum/9;
        int r9 = sum%9;
        for(int i=0;i<num;i++){
            if(t9){
                sol.push_back('9');
                t9--;
            }else if(r9){
                sol.push_back('0'+r9);
                r9 = 0;
            }else{
                sol.push_back('0');
            }
        }
        return sol;
    }
};