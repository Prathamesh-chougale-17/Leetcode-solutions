class Solution {
public:
    int pivotInteger(int n) {
        
        vector<int> arr(n);
        arr[0]=1;
        for(int i=1;i<n;i++){
            arr[i] = arr[i-1] + (i+1);
        }
        for(int i = 1;i<n;i++){
            if(arr[i]==(arr[n-1]-arr[i-1])) return i+1;
            if(arr[i]>(arr[n-1]-arr[i-1])) return -1;
        }
        return 1;
    }
};