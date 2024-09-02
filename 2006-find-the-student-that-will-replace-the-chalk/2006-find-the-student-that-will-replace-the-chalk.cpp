class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int totalchalk = 0;
        for(auto &i:chalk) totalchalk+=i;
        k%=totalchalk;
        if(k){
            for(int i=0;i<chalk.size();i++){
                if(chalk[i]>k) return i;
                k-=chalk[i];
            }
        }
        return 0;
    }
};