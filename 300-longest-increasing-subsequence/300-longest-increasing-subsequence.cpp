class Solution {
public:
    // Best solution is nlogn using Binary Search.
    // TC of following solution is O(n*n), SC - O(n*n);
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0)); // column of dp is n+1 because it will range from -1 to n-1;
        for(int i=nums.size()-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                 int len = dp[i+1][prev+1];
                 if( prev == -1 || nums[prev] < nums[i]) len = max(len, 1 + dp[i+1][i+1]);
                    dp[i][prev+1] = len;
            }
        }
        return dp[0][-1+1];
    }
};
