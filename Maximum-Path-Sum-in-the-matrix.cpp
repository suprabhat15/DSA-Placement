https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
With Recursion => TC - O(3^n*m), SC - O(path length) = O(n)
With Recursion + Memoization => TC - O(n*m) + O(m), SC - O(n*m) // for using dp array.
  
int solve(int row, int col, vector<vector<int>> &matrix, vector<vector<int>>& dp){
    if(row < 0 || col < 0 || col >= matrix[0].size()) return -1e8;
    if(row == 0) return matrix[0][col];
    
    if(dp[row][col] != -1) return dp[row][col];
    
    int up = matrix[row][col] + solve(row-1, col, matrix, dp);
    int leftDiagonal = matrix[row][col] + solve(row-1, col-1, matrix, dp);
    int rightDiagonal = matrix[row][col] + solve(row-1, col+1, matrix, dp);
    
    return dp[row][col] = max(up, max(leftDiagonal, rightDiagonal));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    
    int mx = -1e8;
    vector<vector<int>> dp(row, vector<int>(col, -1));
    
    for(int j=0;j<col;j++){
        int ans = solve(row-1, j, matrix, dp);
        mx = max(ans, mx);
    }
    
    return mx;
}
