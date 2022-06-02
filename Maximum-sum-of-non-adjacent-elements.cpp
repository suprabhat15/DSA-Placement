https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that 
no two elements are adjacent in the given array/list.
--------------------------------------------------------------------------------------
int solve(int idx, vector<int> nums, vector<int>& dp){
    if(idx == 0){
        return nums[0];
    }
    if(idx < 0) return 0;
    if(dp[idx] != -1) return dp[idx];
    
    int pick = nums[idx] + solve(idx-2, nums, dp);
    int notPick = solve(idx-1, nums, dp);
    
    return dp[idx] = max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(n-1, nums, dp);
}
RECURSION -> TC = O(2^n), SC = O(N);
RECURSION + MEMOIZATION -> TC = O(N), SC = O(N) + O(N) {one for recursion stack, other for dp array.}

-----------------------------------------------------------------------------------------------------------
TABULATION
TC = O(N), SC = O(N) {this is for dp array.}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0]=nums[0];
    
    for(int i=1;i<n;i++){
        int pick = nums[i];
        if(i>1) pick += dp[i-2];
        int notPick = dp[i-1];
        
        dp[i] = max(pick, notPick);
    }
    
    return dp[n-1];
}
-------------------------------------------------------------------------------------------------------------
