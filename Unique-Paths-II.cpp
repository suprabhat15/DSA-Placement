https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
--------------------------------------------------------------------------------------------------------------------------------------------
TC => O(m*n), SC => O((m-1)+(n-1)) + O(m*n);
int solve(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(row < 0 || col < 0 || mat[row][col] == -1) return 0;
    if(row == 0 && col == 0) return 1;
    if(dp[row][col] != -1) return dp[row][col];
    int up = solve(row-1, col, mat, dp);
    int left = solve(row, col-1, mat, dp);
    return dp[row][col] = (up + left)%1000000007;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n-1, m-1, mat, dp);
}
