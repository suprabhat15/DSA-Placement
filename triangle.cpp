https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
------------------------------------------------------------------------------------------------------------------------------------------------------------------
With Recursion => TC - O(2^(n*(n+1)/2)), SC => O(path length) = O(n)
With Recursion + Memoization => TC - O(n*(n+1)/2), SC - O(n) + O(n*(n+1)/2) // for using stack space + dp array.
------------------------------------------------------------------------------------------------------------------------------------------------------
int solve(int row, int col, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
    if(row >= n) return 0;
    if(dp[row][col] != -1) return dp[row][col];
    
    int down = triangle[row][col] + solve(row+1, col, triangle, n, dp);
    int diagonal = triangle[row][col] + solve(row+1, col+1, triangle, n, dp);
    
    return dp[row][col] = min(down, diagonal);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n, vector<int>(n,-1));
	return solve(0, 0, triangle, n, dp);
}
