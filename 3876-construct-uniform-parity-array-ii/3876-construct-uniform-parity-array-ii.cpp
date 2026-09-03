class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool fe = false;
        int n = nums1.size();
        sort(nums1.begin(),nums1.end());
        if(nums1[0]%2==0){
            for(int i=1;i<n;i++){
                if(nums1[i]%2)return false;
            }
        }
        return true;
    }
};


/*
2 3

smallest number is even then all should be even

even - odd = odd
even - even = even
odd - odd = odd
odd - even = even


even odd odd odd -> not possible
odd even odd even -> possible

*/