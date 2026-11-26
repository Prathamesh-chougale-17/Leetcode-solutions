class Solution {
    public boolean canAliceWin(int n) {
        int x = 10;
        while(x!=0 && n/x>0){
            n-=x;
            x--;
        }
        return x!=0 && x%2!=0;
    }
}