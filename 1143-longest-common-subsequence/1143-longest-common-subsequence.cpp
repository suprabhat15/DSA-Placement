/*
class Solution {
public:
    //tabulation - O(m*n)

   int longestCommonSubsequence(string text1, string text2){
       int m=text1.length();
    int n=text2.length();
         int dp[m+1][n+1];
       //fill the 0th row and column with values 0
       for(int i=0;i<=m;i++){
           dp[i][0]=0;
       }
        for(int i=0;i<=n;i++){
           dp[0][i]=0;
       }
       for(int i=1;i<=m;i++){
           for(int j=1;j<=n;j++){
               if(text1[i-1]==text2[j-1]){
                   //if char matches then add 1 to the diagonal element then store it 
                   dp[i][j]=1+dp[i-1][j-1];
               }
               else{
                   //pick the max of two i.e non diagonal values 
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               }
           }
       }
       return dp[m][n];
   }
};
*/
class Solution {
    public:
      int lcshelper(int i,string &s1,int j, string &s2,vector<vector<int>> &dp){
        if(i==s1.length() || j==s2.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];

        if(s1[i]==s2[j])
            return dp[i][j]=1+ lcshelper(i+1,s1,j+1,s2,dp);
        else
        {
            int op1= lcshelper(i+1,s1,j,s2,dp);
            int op2= lcshelper(i,s1,j+1,s2,dp);

            return dp[i][j]= max(op1,op2);
        }
    }
    int longestCommonSubsequence(string s, string t) 
    {
        int n1=s.length();
        int n2=t.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return lcshelper(0,s,0,t,dp);
    }
};