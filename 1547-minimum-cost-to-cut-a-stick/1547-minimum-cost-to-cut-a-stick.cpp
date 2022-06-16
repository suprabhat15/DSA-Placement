https://leetcode.com/problems/minimum-cost-to-cut-a-stick/discuss/901997/C%2B%2B-Dynamic-Programming-or-INTUITIVE-or-GIVE-IT-A-READ-or
--------------------------------------------------------------------------------------------------------------------------------------

class Solution
{  
public:

    int minCost(int n, vector<int>& cuts)
    {
        
     //inserting 0 and n as at end points cuts does not signify anything just to 
     //get the length when we are merging.
     cuts.push_back(0); 
     cuts.push_back(n);
        
     //sorting is for so that the you cut your stick in the order
     sort(cuts.begin(),cuts.end());
     
     //dp[i][j] stores the minimum cost  after joining at all the the cuts between i to j
     vector<vector<int> > dp(cuts.size(),vector<int> (cuts.size(),INT_MAX));
    
	// Your base cases stores the answer between [i.i]  and [i][i+1] subarrays or ranges, of size 2 only
     for(int i=0;i<dp.size();i++) dp[i][i]=0;  // base cases as for a point cost is Zero
     for(int i=0;i<dp.size()-1;i++)  dp[i][i+1]=0; //for every two points which constitue a stick is also zero
	 
       
        
     for(int j=2;j<dp.size();j++)
     {
      for(int i=0;i<dp.size()-j;i++)   
      {
        int col=i+j; // your current column
        for(int k=i+1;k<col;k++) //cutting at every k between i to j
        {
         dp[i][col]=min(dp[i][col],dp[i][k]+dp[k][col]+(cuts[col]-cuts[i]));         //adding the final length after your merge            
        }
        }
     }
        
      
     return dp[0][dp.size()-1];   // final answer after joining all the sticks.
        
    }
    

};
