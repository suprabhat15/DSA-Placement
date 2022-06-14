https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
----------------------------------------------------------------------------------------------------------------------------------------
int mod = (int)(1e9+7);
int solve(int idx, vector<int>& num, int tar, vector<vector<int>>& dp){
    if(idx == 0) {
        if(tar == 0 && num[0] == 0) return 2;
        if(tar == 0 || num[0] == tar) return 1;
        return 0;
    }
    
    if(dp[idx][tar] != -1) return dp[idx][tar];
    
    int pick = 0;
    if(num[idx] <= tar) pick = solve(idx-1, num, tar-num[idx], dp);
    
    int notPick = solve(idx-1, num, tar, dp);
    return dp[idx][tar] = (pick + notPick)%mod;
}
int countPartitions(int n, int d, vector<int> &num) {
    int total = 0;
    for(int i=0;i<n;i++) total += num[i];
    
    if( (total < d) || (total-d) % 2 ) return 0;
    vector<vector<int>> dp(num.size(), vector<int>((total-d)/2+1, -1));
    return solve(n-1, num, (total-d)/2, dp);
    
}
 

