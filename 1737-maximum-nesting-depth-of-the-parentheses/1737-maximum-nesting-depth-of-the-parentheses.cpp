class Solution {
public:
    int maxDepth(string s) {
        int count{0},maxi{0};
        // stack st;
        for(auto &i:s){
            if(i=='(')count++;
            else if(i==')')count--;
            maxi=max(maxi,count);
        }
        return maxi;
    }
};