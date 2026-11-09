class Solution {
    public void dfs(int[][] c,int x,int[] vis){
        vis[x] = 1;
        
        for(int i=0;i<c.length;i++){
            if(c[x][i]==1 && vis[i]==0){
                dfs(c,i,vis);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;

        int[] vis = new int[n];

        int s = 0;
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                vis[i]=1;
                dfs(isConnected,i,vis);
                s++;
            }
        }

        return s;
    }
}