class Solution {
public:
    int next[4][2] = {{1, 0}, {-1,0}, {0,1}, {0,-1}};
    int r;
    int c;
    int count = 0;
    int maxCount = 0;

    void dfs (int i, int j, vector<vector<int>>& grid){
        if(i>=r || j>=c || i<0 || j<0 || grid[i][j] == 0){
            return;
        }
        
        if (grid[i][j] == 2) return;
        grid[i][j] = 2;

        count++;
        
        for(int k = 0; k<4; k++){
            int ii = i + next[k][0];
            int jj = j + next[k][1];
            dfs(ii, jj, grid);
            // return count;
        }
        // return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int i , j = 0;

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                // count = 0;
                if(grid[i][j] == 1)
                dfs(i, j, grid);
                maxCount = max(count, maxCount);
                count = 0;
            }
        }    
        return maxCount;
    }
};
