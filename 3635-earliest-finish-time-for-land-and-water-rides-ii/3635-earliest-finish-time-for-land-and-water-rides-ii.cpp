class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int m = ls.size(), n = ws.size(),mini = INT_MAX;
        int minil = INT_MAX, x = 0;
        int miniw = INT_MAX , y = 0;
        for(int i=0;i<m;i++){
            int tmp = ls[i] + ld[i];
            if(minil>tmp){
                minil = tmp;
                x = i;
            }
        }
        for(int i=0;i<n;i++){
            int tmp = ws[i] + wd[i];
            if(miniw>tmp){
                miniw = tmp;
                y = i;
            }
        }
        
        for(int i=0;i<m;i++){
            int tmp = ls[i] + ld[i];
            int tws = miniw>ls[i]?miniw+ld[i]:tmp;
            mini = min(mini,tws);
        }
        for(int i=0;i<n;i++){
            int tmp = ws[i] + wd[i];
            int tls = minil>ws[i]?minil+wd[i]:tmp;
            mini = min(mini,tls);
        }
        return mini;
    }
};