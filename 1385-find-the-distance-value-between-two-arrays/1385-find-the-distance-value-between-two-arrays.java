class Solution {
    public int lowerBound(int[] arr, int target) {
        int low = 0, high = arr.length;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        int sol = 0;
        for(int i:arr1){
            int x = lowerBound(arr2,i);
            if(x>0 && (i-arr2[x-1])<=d){
                continue;
            }else if(x<arr2.length && (arr2[x]-i)<=d){
                continue;
            }
            sol++;
            // System.out.println(i + " " + x + " " + arr2[x-1]);
        }
        return sol;
    }
}