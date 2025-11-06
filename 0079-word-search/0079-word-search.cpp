class Solution {
public:
    bool wordsearch(vector<vector<char>> &board,int m,int n,string word,int i,int j,vector<vector<bool>> &vi){
        if(word.empty())return true;
        if(i>=m || j>=n || i<0 || j<0 || vi[i][j] || board[i][j]!=word[0]) return false;

        vi[i][j]=true;
        bool up = wordsearch(board,m,n,word.substr(1),i-1,j,vi);
        bool down = wordsearch(board,m,n,word.substr(1),i+1,j,vi);
        bool right = wordsearch(board,m,n,word.substr(1),i,j+1,vi);
        bool left = wordsearch(board,m,n,word.substr(1),i,j-1,vi);
        vi[i][j]=false;
        return up || down || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visits(m,vector<bool> (n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (wordsearch(board, m, n, word, i, j, visits))
                    return true; // ✅ only return when found
            }
        }
        return false;
    }
};