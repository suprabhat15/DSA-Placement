class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string> board){
        // upper(row--, col)
        int tempRow = row;
        int tempCol = col;
        while(tempRow >=0){
            if(board[tempRow--][tempCol] == 'Q') return false;
        }
        
        // top right diagonal(row--, col++)
        tempRow = row;
        tempCol = col;
        while(tempRow>=0 && tempCol < n){
            if(board[tempRow--][tempCol++] == 'Q') return false;
        }
        
        // top left diagonal(row--, col--)
        tempRow = row;
        tempCol = col;
        while(tempRow >= 0 && tempCol >= 0){
            if(board[tempRow--][tempCol--] == 'Q') return false;
        }
        
        return true;
    }
    void solve(int row, int n, vector<vector<string>> &ans, vector<string> board){
        if(row == n){
            ans.push_back(board);
            return;
        }
        
        for(int col=0; col<n; ++col){
           if(isSafe(row, col, n, board)){ 
            board[row][col]='Q';
            solve(row+1, n, ans, board);
            board[row][col]='.';
           }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n, '.'); // creating a string with size n having every value '.'
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        solve(0, n, ans, board);
        return ans;
    }
};
