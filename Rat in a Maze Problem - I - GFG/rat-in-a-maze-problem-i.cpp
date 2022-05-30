// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++
------------------------------------------------------------------------------------------------------------------------------------------
 TC - 4^(n*n); // Every cell of n*n will have 4 options (D,L,R,U).
 SC - O(n*n);

class Solution{
    public:
    void solve(int r, int c, int n, vector<vector<int>> &m, string path, vector<string>& ans, vector<vector<int>>& vis){
        if(r == n-1 && c == n-1){
            ans.push_back(path);
            return;
        }
        
        //Down
        if(r+1<n && !vis[r+1][c] && m[r+1][c] == 1){
            vis[r][c]=1;   // vis[r][c] shud be here not vis[r+1][c].
            solve(r+1, c, n, m, path+'D', ans, vis);
            vis[r][c]=0;
        }
        //Left
        if(c-1>=0 && !vis[r][c-1] && m[r][c-1] == 1){
            vis[r][c]=1;    // vis[r][c] shud be here not vis[r][c-1].
            solve(r, c-1, n, m, path+'L', ans, vis);
            vis[r][c]=0;
        }
        //Right
        if(c+1<n && !vis[r][c+1] && m[r][c+1] == 1){
            vis[r][c]=1;    // vis[r][c] shud be here not vis[r][c+1].
            solve(r, c+1, n, m, path+'R', ans, vis);
            vis[r][c]=0;
        }
        //Up
        if(r-1>=0 && !vis[r-1][c] && m[r-1][c] == 1){
            vis[r][c]=1;     // vis[r][c] shud be here not vis[r-1][c].
            solve(r-1, c, n, m, path+'U', ans, vis);
            vis[r][c]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<string> ans;
        if(m[0][0] == 1) solve(0, 0, n, m, "", ans, vis);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
