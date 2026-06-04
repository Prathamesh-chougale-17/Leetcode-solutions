class Solution {
public:
    bool ispeak(int i,int j,int k){
        return i<j && j>k;
    }
    bool isvally(int i,int j,int k){
        return i>j && j<k;
    }
    int totalWaviness(int num1, int num2) {
        if(num2<=100)return 0;
        int ans=0;
        for(int i=num1;i<=num2;i++){
            string s = to_string(i);
            int n = s.size();
            for(int j=0;j<n-2;j++){
                int x = s[j]-'0';
                int y = s[j+1]-'0';
                int z = s[j+2]-'0';
                if(ispeak(x,y,z) || isvally(x,y,z))ans++;
            }
        }
        return ans;
    }
};