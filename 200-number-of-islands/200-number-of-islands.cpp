class Solution {
    bool isSafe(vector<vector<char>>& grid,int r, int c,int row, int col){
        return (r>=0 && r<row && c>=0 && c<col && grid[r][c]=='1');
    }
    
    void dfs(vector<vector<char>>& grid,int r, int c,int row, int col){
        
        grid[r][c]='2';
        int row_neighbour[4]={1,0,-1,0};
        int col_neighbour[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
          if(isSafe(grid,r+row_neighbour[i],c+col_neighbour[i],row,col))   
              dfs(grid,r+row_neighbour[i],c+col_neighbour[i],row,col);
        }
    }
    public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0)return 0;
        int col = grid[0].size();
        
        int cnt=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                { dfs(grid,i,j,row,col);
                    cnt++;
                }
            }
        }
        return cnt;   
    }
};
