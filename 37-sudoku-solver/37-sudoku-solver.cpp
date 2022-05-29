class Solution {
public:
    bool isValid(vector<vector<char>>& board, int r, int c, char ch){
        for(int i=0;i<9;i++){
            if(board[r][i] == ch) return false;
        }
        for(int i=0;i<9;i++){
            if(board[i][c] == ch) return false;
        }
        
        int tempRow = 3*(r/3); // multiplying by 3 here is required to get the starting index of 3*3 matrix.
        int tempCol = 3*(c/3);
        for(int i=tempRow;i<tempRow+3;i++){  // don't write 3*tempRow here as it gives wrong ans.
            for(int j=tempCol;j<tempCol+3;j++){
                if(board[i][j]==ch) return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isValid(board, i, j, ch)){
                            board[i][j]=ch;
                            if(solve(board)== true){
                                return true;
                            }
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};