class Solution {
public:
    bool isSafeForQueen(int n, vector<vector<int>>& board, int row, int col){
      //upward
      for(int i=row-1;i>=0;i--){
          if(board[i][col])return false;
      }
        
        //upper left diagonal
        for(int i=row-1, j=col-1;i>=0 && j>=0;i--,j--){
          if(board[i][j])return false;
      }
        
         //upper right diagonal
        for(int i=row-1, j=col+1;i>=0 && j<n;i--,j++){
          if(board[i][j])return false;
      }
        
      return true;
    }
    
    void placeQueens(int n, vector<vector<string>>& totalAns, vector<vector<int>>& board, int row){
        //Base Case
        if(row == n){
          string temp;
          vector<string> ans;
          for(auto x: board){
              for(auto item: x){
                  if(item)temp+='Q';
                  else temp+='.';
              }
              ans.push_back(temp);
              temp.clear();
          }
             totalAns.push_back(ans);
             // ans.clear();
          return;
        }
        
        for(int col=0;col<n;col++){
            if(isSafeForQueen(n,board,row,col)){
                board[row][col]=1;
                placeQueens(n,totalAns,board,row+1);
                board[row][col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> totalAns;
        vector<vector<int>> board(n, vector<int>(n,0));
        placeQueens(n,totalAns,board,0);
        return totalAns;
    }
};
