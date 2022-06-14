https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
--------------------------------------------------------------------------------------------------------------------------------------------------------
With Recursion => TC - O(2^n), SC - O(n);
With Recursion + Memoization => TC - O(n*target), SC - O(n*target);

int solve(int idx, vector<int>& num, int tar, vector<vector<int>>& dp){
    if(tar == 0) return 1;
    if(idx == 0) return num[idx] == tar;
    
    if(dp[idx][tar] != -1) return dp[idx][tar];
    
    int pick = 0;
    if(num[idx] <= tar) pick = solve(idx-1, num, tar-num[idx], dp);
    
    int notPick = solve(idx-1, num, tar, dp);
    return dp[idx][tar] = pick + notPick;
}
int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> dp(num.size(), vector<int>(tar+1, -1));
    return solve(num.size()-1, num, tar, dp);
}
---------------------------------------------------------------------------------------------------------------------------------------------------------
Check DP-18 for corner cases including 0 like {0, 0, 1}. In this case, there will be 4 ways to sum = 1.
For tackling above corner case, we need to 
1. remove the 7th line.
2. add the following line - 
    if(i == 0){
      if(sum == 0 && arr[0] == 0) return 2; //cuz either we pick or notPick arr[0], there will be no impact on our ans. but count will increase.
      if(sum == 0 || sum == arr[0]) return 1;
      return 0;  // for all other cases.
    }
https://www.youtube.com/watch?v=zoilQD1kYSg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=19
