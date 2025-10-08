class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        vector<int> temp = s;
        sort(s.begin(),s.end());
        sort(p.begin(),p.end());
        int n = s.size();
        int m = p.size();
        long long mul = 0;
        int sp = 0;
        int i = 0, j = m - 1;
        unordered_map<int,int> um;
        vector<int> ans;
        while(i<n){
            if(j==-1||((s[i]*1LL*p[j])<success)){
                // ans.push_back(sp);
                cout<<sp<<endl;
                um[s[i]]=sp;
                i++;
            }else{
                sp++;
                j--;
            }
        }
        for(auto &i:temp){
            ans.push_back(um[i]);
        }
        return ans;
    }
};