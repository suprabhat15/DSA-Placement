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