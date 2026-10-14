class Solution {
    public String maxSumOfSquares(int num, int sum) {
        if(num*9<sum)return "";
        int n9 = sum/9;
        int r9 = sum%9;
        StringBuilder sol = new StringBuilder("0".repeat(num));
        for(int i=0;i<num;i++){
            if(n9>0){
                sol.setCharAt(i,'9');
                n9--;
            }else{
                sol.setCharAt(i,(char)(r9+'0'));
                return sol.toString();
            }
        }
        return sol.toString();
    }
}