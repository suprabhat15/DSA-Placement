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
        
// int Max = amount + 1;
//         vector<int> dp(amount + 1, Max);
//         dp[0] = 0;
//         for (int i = 1; i <= amount; i++) {
//             for (int j = 0; j < coins.size(); j++) {
//                 if (coins[j] <= i) {
//                     dp[i] = min(dp[i], dp[i - coins[j]] + 1);
//                 }
//             }
//         }
//         return dp[amount] > amount ? -1 : dp[amount];
    }
};

*/
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