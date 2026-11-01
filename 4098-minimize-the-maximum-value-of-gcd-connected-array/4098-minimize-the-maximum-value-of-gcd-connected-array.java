class Solution {
    public int minD(int val){
        for(int i=2;i*i<=val;i++){
            if(val%i==0)return i;
        }
        return val;
    }
    public long minimumMaxValue(int n, int index, int value) {
        int m = minD(value);
        
        if(value<=1 || (value-m)/2<index)return -1;
        if(value%2==1) return (long)(value + m + (long)(n-2-index)*2);
        return (long)(value + (long)2*(n-1-index));
    }
}