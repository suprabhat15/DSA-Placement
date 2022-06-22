class Solution {
public:
    void fillAll(vector<vector<int>>& image, int sr, int sc, int newColor, vector<vector<int>>& vis, int oldColor){
        // base case
        if(sr < 0 or sc < 0 or sr >= image.size() or sc >= image[0].size() or vis[sr][sc] or image[sr][sc] != oldColor) return;
        
        vis[sr][sc]=1;
        image[sr][sc] = newColor;
        fillAll(image, sr-1, sc, newColor, vis, oldColor);  // up
        fillAll(image, sr, sc-1, newColor, vis, oldColor); // left
        fillAll(image, sr+1, sc, newColor, vis, oldColor); // down
        fillAll(image, sr, sc+1, newColor, vis, oldColor); // right
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int r = image.size();
        int c = image[0].size();
        int oldColor = image[sr][sc];
        vector<vector<int>> vis(r, vector<int> (c, 0));
        fillAll(image, sr, sc, newColor, vis, oldColor);
        return image;
    }
};