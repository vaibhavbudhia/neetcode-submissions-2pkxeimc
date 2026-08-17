class Solution {
public:
    int next[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int r, c;

    void dfs(int sr, int sc, int org_color, int color, vector<vector<int>>& image) {

        if (sr < 0 || sc < 0 || sr >= r || sc >= c || image[sr][sc] != org_color) {
            return;
        }
        
        image[sr][sc] = color;

        for (int i = 0; i < 4; i++) {
            int new_x = sr + next[i][0];
            int new_y = sc + next[i][1];

            dfs(new_x, new_y, org_color, color, image);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        r = image.size();
        c = image[0].size();

        int org_color = image[sr][sc];

        if (org_color == color) return image;
 
        // image[sr][sc] = color;

        dfs(sr, sc, org_color, color, image);

        return image;
    }
};