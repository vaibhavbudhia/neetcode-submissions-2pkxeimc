class Solution {
public:
int next[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};

    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;

        queue<pair<int,int>> q;

        for(int i = 0; i<r; i++){
            for (int j = 0; j<c; j++){
                if(grid[i][j] == 2) q.push({i,j});
            }
        }

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i<size; i++){
                pair<int, int> f = q.front();
                q.pop();

                for(int k = 0; k<4; k++){
                    int new_x = f.first + next[k][0];
                    int new_y = f.second + next[k][1];

                    if(new_x < 0 || new_y < 0 || new_x >= r || new_y >= c ||                        grid[new_x][new_y] != 1){
                        continue;
                    }
                    grid[new_x][new_y] = 2;
                    q.push({new_x, new_y});
                }
            }
            if(!q.empty()) count++;
        }

        for(auto &v : grid){
            for(int &x : v) if(x == 1) return -1;
        }
        
        return count;
    }
};
