class Solution {
public:

    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int r, c;

    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j] != '1'){
            return;
        }   
        grid[i][j] = '2';

        for(int k = 0; k<4; k++){
            int ii = i+next[k][0]; 
            int jj = j+next[k][1]; 
            dfs(grid, ii, jj);    
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        r = grid.size();
        c = grid[0].size();

        for(int i  =0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j] == '1'){
                dfs(grid, i, j);
                count++;
                }
            }
        }
        return count;
    }
};