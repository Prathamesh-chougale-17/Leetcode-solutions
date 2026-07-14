class Solution {
public:
    bool isSafe(int row,int col,vector<string> &board,int n){
        int rd = row,cd = col;
        while(rd>=0 && cd>=0){
            if(board[rd][cd]=='Q')return false;
            rd--;
            cd--;
        }
        rd = row,cd = col;
        while(cd>=0){
            if(board[rd][cd]=='Q')return false;
            cd--;
        }
        rd = row,cd = col;
        while(rd<n && cd>=0){
            if(board[rd][cd]=='Q')return false;
            rd++;
            cd--;
        }
        return true;
    }
    void solve(vector<vector<string>> &sol,vector<string> &board,int n,int ind){
        if(ind == n){
            sol.push_back(board);
            return;
        }
        for(int row = 0;row<n;row++){
            if(isSafe(row,ind,board,n)){
                board[row][ind]='Q';
                solve(sol,board,n,ind+1);
                board[row][ind]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        vector<string> board;
        string tmp(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(tmp);
        }
        solve(sol,board,n,0);
        return sol;
    }
};