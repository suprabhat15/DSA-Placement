// Method 1
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


// Method 2
class Solution {
public:
    void solve(int col, int n, vector<string> board, vector<vector<string>> &ans, vector<int> lowerDiagonal, vector<int> upperDiagonal, vector<int> horizontalRow) {
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; ++row){
            if(lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0 && horizontalRow[row] == 0){
               lowerDiagonal[row+col]=1;
               upperDiagonal[n-1+col-row]=1;
               horizontalRow[row]=1;
               board[row][col]='Q';
               solve(col+1, n, board, ans, lowerDiagonal, upperDiagonal, horizontalRow);
               lowerDiagonal[row+col]=0;
               upperDiagonal[n-1+col-row]=0;
               horizontalRow[row]=0;
               board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n, '.');
        for(int i=0; i<n;i++){
            board.push_back(s);
        }
        vector<int> lowerDiagonal(2*n-1, 0), upperDiagonal(2*n-1, 0), horizontalRow(n, 0); // method using hashmap
        solve(0, n, board, ans, lowerDiagonal, upperDiagonal, horizontalRow);
        return ans;
    }
};
