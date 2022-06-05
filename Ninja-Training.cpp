https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
---------------------------------------------------------------------------------------------------------------------------------------------------------------
TC - O(N*4)*3
SC - O(N) + O(N*4); 
solve(i,j) means , maximum points till day i when previously task j was done.
  int solve(int day, int prev, vector<vector<int>> &points, vector<vector<int>>& dp){  // I had forgot to add '&' before 'points'. So, I was getting TLE.
    if(day == 0){
        int maxi = 0;
        for(int task=0;task<3;task++){
            if(task!=prev){
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    
    if(dp[day][prev] != -1) return dp[day][prev];
    
    int maxi = 0;
    for(int task=0;task<3;task++){
        if(task!=prev){
            int value = points[day][task] + solve(day-1, task, points, dp);
            maxi = max(maxi, value);
        }
    }
    
    return dp[day][prev] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int> (4, -1));
    return solve(n-1, 3, points, dp);
}
