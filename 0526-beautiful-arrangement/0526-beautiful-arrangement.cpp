class Solution {
public:
    void back(int &n,int &x,int &sol,vector<bool> &used){
        if(x==n){
            sol++;
            return;
        }
        for(int i=1;i<=n;i++){
            if(!used[i-1] && (i%(x+1)==0 || (x+1)%i==0)){
                x++;
                cout<<x<<endl;
                used[i-1]=true;
                back(n,x,sol,used);
                used[i-1]=false;
                x--;
            }
        }
    }
    int countArrangement(int n) {
        int x = 0;
        int sol = 0;
        vector<bool> used(n,false);
        back(n,x,sol,used);
        return sol;
    }
};