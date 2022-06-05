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

----------------------------------------------------------------------------------------------------------------------------
TC - O(N);
SC - O(N*4);
  int ninjaTraining(int n, vector<vector<int>> &points)
{
   vector<vector<int>> dp(n, vector<int> (3, 0));
    
    dp[0][0] = points[0][0];  // dp[i][j] denotes maxPoints gained by ninja till i days where last performed task is jth index on same day.
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];
    
    int maxPoints = max(dp[0][0], max(dp[0][1], dp[0][2]));
    
    for(int i=1;i<points.size();i++){
        dp[i][0] = points[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = points[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = points[i][2] + max(dp[i-1][0], dp[i-1][1]);
        
        maxPoints = max(dp[i][0], max(dp[i][1], dp[i][2]));
    }
    
    return maxPoints;
}
