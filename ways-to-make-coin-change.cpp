https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
---------------------------------------------------------------------------------------------------------------------
With Recursion => TC - EXPONENTIAL, SC - >> O(N) in worst case, it can be O(Target)
With Recursion + Memoization => TC - O(n*target), SC - O(n*target) + O(Target) // one for dp table and other for recursion stack space.
  
#include<bits/stdc++.h>
long solve(int idx, int* denominations, int target, vector<vector<long>>& dp){
    if(idx == 0){
        return (target%denominations[0] == 0);
    }
    
    if(dp[idx][target] != -1) return dp[idx][target];
    // notTake
    long notTake = solve(idx-1, denominations, target, dp);
    
    long take = 0;
    //take
    if(denominations[idx] <= target) take = solve(idx, denominations, target-denominations[idx], dp);
    
    return dp[idx][target] = take+notTake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, -1));
   return solve(n-1, denominations, value, dp);
}

-----------------------------------------------------------------------------------------------------------------------
Tabulation => TC - O(n*target), SC - O(n*target);

#include<bits/stdc++.h>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, 0));
    for(int target = 0; target <= value; target++){
        dp[0][target] = (target%denominations[0] == 0);
    }
    
    for(int idx = 1; idx<n ; idx++){
        for(int target = 0; target <= value; target++){
        long notTake = dp[idx-1][target];
        long take = 0;

        if(denominations[idx] <= target) take = dp[idx][target-denominations[idx]];
            dp[idx][target] = take + notTake;
        }
    }
   return dp[n-1][value];
}
------------------------------------------------------------------------------------------------------------------------
Space Optimization - TC - O(n*target), SC - O(2*target);
  
  #include<bits/stdc++.h>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long> prev(value+1, 0), curr(value+1, 0);
    
    for(int target = 0; target <= value; target++){
        prev[target] = (target%denominations[0] == 0);
    }
    
    for(int idx = 1; idx<n ; idx++){
        for(int target = 0; target <= value; target++){
        long notTake = prev[target];
        long take = 0;

        if(denominations[idx] <= target) take = curr[target-denominations[idx]];
            curr[target] = take + notTake;
        }
        prev = curr;
    }
   return prev[value];
}
