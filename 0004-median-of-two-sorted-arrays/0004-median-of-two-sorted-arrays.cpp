class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int i=0,j=0,m = nums1.size(), n = nums2.size();
        while(i<m && j<n){
            if(nums1[i]>nums2[j]){
                arr.push_back(nums2[j]);
                j++;
            }else{
                arr.push_back(nums1[i]);
                i++;
            }
        }
        while(i<m){
            arr.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            arr.push_back(nums2[j]);
            j++;
        }
        double ans;
        int x = arr.size();
        if(x&1){
            ans = arr[x/2];
        }else{
            ans = (double(arr[x/2]) + double(arr[(x/2) - 1]))/2;
        }
        return ans;

    }
};