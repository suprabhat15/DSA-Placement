/*
// With Recursion
class Solution {
public:
    bool solve(int idx, vector<int>& nums, int target){
        if(idx >= nums.size()) return false;
        if(target == 0) return true;
        
        //pick
        bool pick = false;
        if(nums[idx] <= target) pick = solve(idx+1, nums, target-nums[idx]);
        // notPick
        bool notPick = solve(idx+1, nums, target);
        
        return pick | notPick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x: nums) sum+=x;
        
        if(sum%2) return false;
        return solve(0, nums, sum/2);
    }
};
*/

class Solution {
public:
    int solve(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
    if(target == 0) return 1;
    if(idx == 0) return target == nums[idx];
    
    if(dp[idx][target] != -1) return dp[idx][target];
    int take = 0;
    if(nums[idx] <= target) take = solve(idx-1, target-nums[idx], nums, dp);
    int notTake = solve(idx-1, target, nums, dp);
    
    return dp[idx][target] = take | notTake;
}
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x: nums) sum+=x;
        
        if(sum%2) return false;
        
        int target = sum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));  // sum/2+1 is required, otherwise error.
        return solve(nums.size()-1, target, nums, dp);
    }
};