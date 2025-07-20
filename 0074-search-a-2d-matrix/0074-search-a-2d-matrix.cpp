class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int l = 0, r = m.size()*m[0].size()-1,cs = m[0].size();
        while(l<=r){
            int mid = l + (r-l)/2;
            if(m[mid/cs][mid%cs]==target) return true;
            else if(m[mid/cs][mid%cs]>target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return false;
    }
};