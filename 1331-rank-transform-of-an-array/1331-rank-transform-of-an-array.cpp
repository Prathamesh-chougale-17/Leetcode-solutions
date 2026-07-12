class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>> mv;
        int n = arr.size();
        for(int i=0;i<n;i++){
            mv[arr[i]].push_back(i);
        }
        int tmp = 0;
        for(auto &i:mv){
            tmp++;
            for(auto &j:i.second){
                arr[j]=tmp;
            }
        }
        return arr;
    }
};