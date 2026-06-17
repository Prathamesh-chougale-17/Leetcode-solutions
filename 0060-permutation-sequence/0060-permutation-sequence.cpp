class Solution {
public:
    int fact(int n){
        int per = 1;
        while(n>1){
            per *= n;
            n = n-1;
        }
        return per;
    }
    string getPermutation(int n, int k) {
        string tmp;
        for(int i=0;i<n;i++){
            tmp.push_back(char('0'+i+1));
        }
        string sol;
        k = k-1;
        while(k>0){
            int f = fact(--n);
            int d = k/f;
            k = k%f;
            sol+=tmp[d];
            for(int i=d;i<n;i++)swap(tmp[i],tmp[i+1]);
            tmp.pop_back();
        }
        return sol+tmp;
    }
};