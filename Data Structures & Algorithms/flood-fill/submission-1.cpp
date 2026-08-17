class Solution {
public:
    
    int next[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
    int color) {
    
        int r = image.size();
        int c = image[0].size();

        queue<pair<int, int>> q;
        int org_color = image[sr][sc];

        if (org_color == color)
            return image;

        q.push({sr, sc});
        image[sr][sc] = color;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                pair<int, int> f = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int new_x = f.first + next[i][0];
                    int new_y = f.second + next[i][1];

                    if (new_x < 0 || new_y < 0 || new_x >= r || new_y >= c ||
                        image[new_x][new_y] != org_color) {
                        continue;
                    }
                    image[new_x][new_y] = color;
                    q.push({new_x, new_y});
                }
            }
        }
        return image;
    }
};