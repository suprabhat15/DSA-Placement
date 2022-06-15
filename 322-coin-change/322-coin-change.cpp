/*
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // if(amount == 0) return 0;
       // int dp[10001];
        vector<int> dp(amount + 1, 10001);
        dp[0]=0;
       // memset(dp, amount+1, amount+1);
       int n = coins.size(); 
      
      for(int i=1;i<=amount;i++){
          for(int j=0;j<n;j++){
             if(coins[j] <= i) dp[i] = min(dp[i],dp[i-coins[j]] + 1);
          }
      }
        // for(auto x: dp) cout<<x<<" ";
        return dp[amount] > amount ? -1 : dp[amount];
      
--------------------------------------------------------------------------

         int Max = amount + 1;
         vector<int> dp(amount + 1, Max);
         dp[0] = 0;
         for (int i = 1; i <= amount; i++) {
             for (int j = 0; j < coins.size(); j++) {
                 if (coins[j] <= i) {
                     dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                 }
             }
         }
         return dp[amount] > amount ? -1 : dp[amount];
         
---------------------------------------------------------------------------
With Recursion => TC - EXPONENTIAL, SC - >> O(n) (way greater than Big O(n) )
With Recursion + Memoization => TC - O(n*target), SC - O(n*target) + O(target) // when arr is of length 1 having only value 1 and target = 10000. 
                                                                               // Then, target/arr[0] will be space complexity.

class Solution {
public:
    int solve(int idx, vector<int>& coins, int target, vector<vector<int>>& dp){
        if(idx == 0){
            
            if(target%coins[0] == 0) return target/coins[0];
            return 1e9;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int notTake = solve(idx-1, coins, target, dp);
        
        int take = 1e9;
        if(coins[idx]<=target) take = 1 + solve(idx, coins, target-coins[idx], dp);
        
        return dp[idx][target] = min(notTake, take);
        
    }
    
    int coinChange(vector<int>& coins, int target) {
        vector<vector<int>> dp(coins.size(), vector<int>(target+1, -1));
        
        int ans = solve(coins.size()-1, coins, target, dp);
        
        return ans >= 1e9 ? -1 : ans;
    }
};

------------------------------------------------------------------------------------
Tabulation => TC - O(n*target), SC - O(n*target);

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        
        for(int target = 0; target <= amount; target++) {
            if(target%coins[0] == 0) dp[0][target] = target/coins[0];
            else dp[0][target] = 1e9;
        }
        
        for(int idx = 1; idx < coins.size(); idx ++) {
            for(int target=0; target<=amount; target++){
                int notTake = dp[idx-1][target];
        
                int take = 1e9;
                if(coins[idx]<=target) take = 1 + dp[idx][target-coins[idx]];

                dp[idx][target] = min(notTake, take);
            }
        }
    
        
        return dp[coins.size()-1][amount] >= 1e9 ? -1 : dp[coins.size()-1][amount];
    }
};

----------------------------------------------------------------------------------------
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> prev(amount+1, 0), curr(amount+1, 0);
        
        for(int value = 0; value <= amount; value++) {
            if(value%coins[0] == 0) prev[value] = value/coins[0];
            else prev[value] = 1e9;
        }
        
        for(int idx = 1; idx < coins.size(); idx ++) {
            for(int target=0; target<=amount; target++){
                int notTake = prev[target];
        
                int take = 1e9;
                if(coins[idx]<=target) take = 1 + curr[target-coins[idx]];

                curr[target] = min(notTake, take);
            }
            prev = curr;
        }
    
        
        return prev[amount] >= 1e9 ? -1 : prev[amount];
    }
};
