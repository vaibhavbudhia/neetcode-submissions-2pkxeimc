class Solution {
public:

    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int r, c;
    int count = 0;

    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j] == 0){
            count++;
            return;
        }   
        if(grid[i][j] == 2) return;

        grid[i][j] = 2;

        for(int k = 0; k<4; k++){
            int ii = i+next[k][0]; 
            int jj = j+next[k][1]; 
            dfs(grid, ii, jj);    
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        // int count = 0;
        r = grid.size();
        c = grid[0].size();

        for(int i  =0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j] == 1){
                dfs(grid, i, j);
                return count;
                }
            }
        }
        return 0;
    }
};