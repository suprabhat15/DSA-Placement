// Following solution will give TLE but for developing intuition, it's good.
class Solution {
public:
    int solve(vector<int>& nums, int idx, int prev, vector<vector<int>>& dp){
        if(idx >= nums.size()) return 0;
        
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        
        int len = solve(nums, idx+1, prev, dp);
        if( prev == -1 || nums[prev] < nums[idx]) len = max(len, 1 + solve(nums, idx+1, idx, dp));
        return dp[idx][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1)); // column of dp is n+1 because it will range from -1 to n-1;
        return solve(nums, 0, -1, dp);  // passing index as 0 and prevIndex as -1 showing no value is selected as prevIndex for the very first time.
    }
};
----------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    // Best solution is nlogn using Binary Search.
    // TC of following solution is O(n*n), SC - O(n*n);
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0)); // column of dp is n+1 because it will range from -1 to n-1;
        for(int i=nums.size()-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){  // here prev = i-1 because prevIndex is always behind the index. Here, idx = i, prevIndex = i-1;
                 int len = dp[i+1][prev+1];  // move ahead without counting the nums[i] i.e., not pick; 
                                             // prev+1 means since we didn't pick the current index, So, prev will remain same. 
                                             // For handling -1 as prevIndex, we are using prevIndex+1;
                 if( prev == -1 || nums[prev] < nums[i]) len = max(len, 1 + dp[i+1][i+1]);  // [i+1] is for moving ahead. another [i+1] because the current index becomes 
                                                                                            // prevIndex for the next Index. +1 for handling -1 prevIndex.
                    dp[i][prev+1] = len;
            }
        }
        return dp[0][-1+1];  // the answer will be stored at [0][-1].
    }
};
