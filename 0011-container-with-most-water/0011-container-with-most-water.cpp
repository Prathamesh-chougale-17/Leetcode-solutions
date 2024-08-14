class Solution {
public:
    int maxArea(vector<int>& height) {
        int f{0},l = height.size()-1,maxi{0};
        while(f<l){
            maxi = max(maxi,min(height[f],height[l])*(l-f));
            if(height[f]>height[l]) l--;
            else f++;
        }
        return maxi;
    }
};