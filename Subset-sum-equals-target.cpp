https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0
----------------------------------------------------------------------------------------------------------------------------------
With Recursion - TC - O(2^n), SC - O(n);
With Recursion + Memoization => TC - O(n*target), SC - O(n*target);

int solve(int idx, int target, vector<int>& arr, vector<vector<int>>& dp){
    if(target == 0) return 1;
    if(idx == 0) return target == arr[idx];
    
    if(dp[idx][target] != -1) return dp[idx][target];
    int take = 0;
    if(arr[idx] <= target) take = solve(idx-1, target-arr[idx], arr, dp);
    int notTake = solve(idx-1, target, arr, dp);
    
    return dp[idx][target] = take | notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));  // k+1 is required, otherwise error.
    return solve(n-1, k, arr, dp);
}
