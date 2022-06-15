https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
VIDEO LINK - https://www.youtube.com/watch?v=GqOmJHQZivw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=20
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// With Recursion => TC - O(2^n), SC - O(n);
// With Recursion + Memoization => TC - O(n*maxW), SC - O(n*maxW) + O(n) // one for dp table, another for Recursion Stack Space;

int solve(int idx, vector<int>& weight, vector<int>& value, int maxW, vector<vector<int>>& dp){
    if(idx == 0){
        if(weight[0] <= maxW) return value[0];
        return 0;
    }
    if(dp[idx][maxW] != -1) return dp[idx][maxW];
    int notPick = solve(idx-1, weight, value, maxW, dp);
    int pick = INT_MIN;
    if(weight[idx] <= maxW) 
        pick = value[idx] + solve(idx-1,weight, value, maxW - weight[idx], dp);
    
    return dp[idx][maxW] = max(pick, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxW) 
{
    vector<vector<int>> dp(n, vector<int>(maxW+1, -1));
	return solve(n-1, weight, value, maxW, dp);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Tabulation => TC - O(n*maxW), SC - O(n*maxW) // NO RECURSION STACK SPACE
  
int knapsack(vector<int> weight, vector<int> value, int n, int maxW) 
{
    vector<vector<int>> dp(n, vector<int>(maxW+1, 0));
    for(int wt = weight[0];wt<=maxW; wt++) dp[0][wt] = value[0]; // pick those items only whose weight <= updatedWeight of the bag.
    for(int idx=1;idx<n;idx++){
        for(int W=0;W<=maxW;W++){
            int notPick = dp[idx-1][W];
            int pick = INT_MIN;
            if(weight[idx] <= W) 
                pick = value[idx] + dp[idx-1][W-weight[idx]];
            dp[idx][W] = max(pick, notPick);
        }
    }
	return dp[n-1][maxW];
}
-------------------------------------------------------------------------------------------------------------------------------------------------------------
// Space Optimization =>  TC - O(n*maxW), SC - O(2*maxW) // for using prev and curr arrays
  
int knapsack(vector<int> weight, vector<int> value, int n, int maxW) 
{
    vector<int> prev(maxW+1, 0), curr(maxW+1, 0);
    for(int wt = weight[0];wt<=maxW; wt++) prev[wt] = value[0]; // pick those items only whose weight <= updatedWeight of the bag.
    for(int idx=1;idx<n;idx++){
        for(int W=0;W<=maxW;W++){
            int notPick = prev[W];
            int pick = INT_MIN;
            if(weight[idx] <= W) 
                pick = value[idx] + prev[W-weight[idx]];
            curr[W] = max(pick, notPick);
        }
        prev = curr;
    }
	return prev[maxW];
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------
// Single Array Space Optimized Solution

int knapsack(vector<int> weight, vector<int> value, int n, int maxW) 
{
    vector<int> prev(maxW+1, 0);
    for(int wt = weight[0];wt<=maxW; wt++) prev[wt] = value[0]; // pick those items only whose weight <= updatedWeight of the bag.
    for(int idx=1;idx<n;idx++){
        for(int W=maxW;W>=0;W--){  // Even on running loop in decreasin order, we get answer because W-weight always lie on the left side of particular index.
                                  // Hence, computing the very last n-1 won't impact the solution. 
            int notPick = prev[W];
            int pick = INT_MIN;
            if(weight[idx] <= W) 
                pick = value[idx] + prev[W-weight[idx]];
            prev[W] = max(pick, notPick);
        }
    }
	return prev[maxW];
}


  
