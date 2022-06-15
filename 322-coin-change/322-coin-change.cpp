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
