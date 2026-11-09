class Solution {
    public void dfs(int[][] image,int i,int j,int c,int lc){
        if(i<0 || j<0 || j>=image[0].length || i>=image.length || image[i][j]!=lc)return;
        image[i][j] = c;
        dfs(image,i+1,j,c,lc);
        dfs(image,i-1,j,c,lc);
        dfs(image,i,j+1,c,lc);
        dfs(image,i,j-1,c,lc);
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        if(image[sr][sc]==color)return image;
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
}