class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long ans=0;
        int n = skill.size();
        int temp=skill[0]+skill[n-1];
        for(int i=0;i<n/2;i++){
            if(temp==(skill[i]+skill[n-i-1]))ans+=(skill[i]*skill[n-i-1]);
            else{
                return -1;
            }
        }
        return ans;
    }
};