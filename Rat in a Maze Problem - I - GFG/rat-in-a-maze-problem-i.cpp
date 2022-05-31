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

--------------------------------------------------------------------------------------------------------------------------------
 
 class Solution{
    public:
    void solve(int row, int col, string s, vector<vector<int>> m, vector<vector<int>>& vis,
    vector<string>& ans, int n){
        if(row == n-1 && col == n-1){
            ans.push_back(s);
            return;
        }
        
        int dx[]={1, 0, 0, -1};
        int dy[]={0, -1, 1, 0};
        string path="DLRU";
        for(int i=0;i<4;i++){
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n 
            && m[newRow][newCol] == 1 && !vis[newRow][newCol]){
                vis[row][col] = 1;
                solve(newRow, newCol, s+path[i], m, vis, ans, n);
                vis[row][col] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if(m[0][0]==1)solve(0, 0, "", m, vis, ans, n);
        return ans;
    }
};

