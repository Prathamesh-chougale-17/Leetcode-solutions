class Solution {
    public String[] createGrid(int m, int n) {
        String[] sol = new String[m];
        for(int i=0;i<m;i++){
            StringBuilder s = new StringBuilder();
            for(int j=0;j<n;j++){
                if(i==0 || j == (n-1)){
                    s.append('.');
                }else{
                    s.append('#');
                }
            }
            sol[i]=s.toString();
        }
        return sol;
    }
}