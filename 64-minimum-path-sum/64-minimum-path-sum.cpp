With Recursion => TC - O(2^(m*n)), SC - O((M-1)+(N-1));  // (M-1)+(N-1) is path length.
With Recursion + Memoization => TC - O(m*n), SC - O((M-1)+(N-1)) + O(m*n) // Path Length + for using DP matrix.
---------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp){
        if(row == 0 && col ==0){
            return grid[row][col];
        }
        if(row < 0 || col < 0) return 9999;
        if(dp[row][col] != -1) return dp[row][col];
        
        int up = grid[row][col] + solve(grid, row-1, col, dp);
        int left = grid[row][col] + solve(grid, row, col-1, dp);
        
        return dp[row][col] = min(up, left);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        
        return solve(grid, row-1, col-1, dp);
    }
};
--------------------------------------------------------------------------------------------------------------
Tabulation => TC - O(m*n), SC - O(m*n);
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i == 0 && j == 0) dp[0][0] = grid[0][0];   // dp[i][j] denotes minimum path sum till ith row and jth column.
                else{
                    int up = 9999, left = 9999;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }
        return dp[row-1][col-1];
    }
};
