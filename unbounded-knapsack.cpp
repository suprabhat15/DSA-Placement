----------------------------------------------------------------------------------------------------------- 
Here, weight means W(weight of thief's bag) in TC & SC.
                     
With Recursion => TC - EXPONENTIAL, SC - O(weight); 
With Recursion + Memoization => TC - O(n*weight), SC - O(n*weight) + O(weight);

int solve(int idx, int w, vector<int>& profit, vector<int>& weight, vector<vector<int>>& dp){
    if(idx == 0){
        return (w/weight[0])*profit[0];
    }
    
    if(dp[idx][w] != -1) return dp[idx][w];
    int notTake = solve(idx-1, w, profit, weight, dp);
    int take = 0;
    if(weight[idx] <= w) take = profit[idx] + solve(idx, w-weight[idx], profit, weight, dp);
    
    return dp[idx][w] = max(take, notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return solve(n-1, w, profit, weight, dp);
}

-------------------------------------------------------------------------------------------------------------
Tabulation => TC - O(n*weight), SC - O(n*weight);

int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(W+1, 0));
    for(int w = 0; w<=W; w++) dp[0][w] = (w/weight[0])*profit[0];
    
    for(int idx = 1; idx<n; idx++){
        for(int w=0; w<=W; w++){
            int notTake = dp[idx-1][w];
            int take = 0;
            if(weight[idx] <= w) take = profit[idx] + dp[idx][w-weight[idx]];

            dp[idx][w] = max(take, notTake);
        }
    }
    return dp[n-1][W];
}

--------------------------------------------------------------------------------------------------------------
Space Optimization => TC - O(n*weight), SC - O(2*weight);
int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(W+1, 0), curr(W+1, 0);
    
    for(int w = 0; w<=W; w++) prev[w] = (w/weight[0])*profit[0];
    
    for(int idx = 1; idx<n; idx++){
        for(int w=0; w<=W; w++){
            int notTake = prev[w];
            int take = 0;
            if(weight[idx] <= w) take = profit[idx] + curr[w-weight[idx]];

            curr[w] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[W];
}

  

