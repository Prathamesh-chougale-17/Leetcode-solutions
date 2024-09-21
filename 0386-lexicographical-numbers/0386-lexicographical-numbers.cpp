class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int cu = 1;
        for(int i=0;i<n;i++){
            ans.push_back(cu);
            if(cu*10 <=n){
                cu*=10;
            }
            else{
                while(cu%10==9 || cu+1>n){
                    cu/=10;
                }
                cu++;
            }
        }
        return ans;
    }
};