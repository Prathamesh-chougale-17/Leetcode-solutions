class Solution {
    public int numberOfSubstrings(String s) {
        int i = 0, j = 2,n = s.length(),sol = 0;
        int[] arr = new int[3];
        for(int z=0;z<3;z++){
            arr[s.charAt(z)-'a']++;
        }
        while(j<n){
            int x = 1;
            for(int z=0;z<3;z++){
                x*=arr[z];
            }
            if(x>0){
                sol+=(n-j);
                arr[s.charAt(i)-'a']--;
                i++;
            }else{
                j++;
                if(j<n)
                    arr[s.charAt(j)-'a']++;
            }
        }
        return sol;
    }
}