class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(),c = 0;
        vector<int> sol;
        digits[n-1]=digits[n-1]+1;
        c = digits[n-1]/10;
        if(c)digits[n-1]=0;
        for(int i=1;i<n;i++){
            if(c){
                int z = digits[n-i-1];
                digits[n-i-1]=(z+c)%10;
                c = (z+c)/10;
                cout<<c<<endl;
            }
        }
        if(c){
            sol.push_back(1);
            for(auto &i:digits){
                sol.push_back(i);
            }
        }else{
            sol = digits;
        }
        return sol;
    }
};