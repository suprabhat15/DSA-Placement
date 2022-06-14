class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int r=grid.size(), c=grid[0].size();
        int total=0, cnt=0, rotten=0, minutes=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c; j++){
                if(grid[i][j] != 0) total++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        
        int dx[4]={-1, 1, 0, 0};
        int dy[4]={0, 0, 1, -1};
        while(!q.empty()){
            rotten = q.size();
            cnt += rotten;
            while(rotten--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx>=r || nx<0 || ny<0 || ny>=c || grid[nx][ny] != 1) continue ;
                    q.push({nx, ny});
                    grid[nx][ny]=2;
                }
            }
            if(!q.empty()) minutes++;
        }
        return total == cnt ? minutes : -1;
    }
};