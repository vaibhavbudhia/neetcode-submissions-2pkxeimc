class Solution {
public:
int next[8][2] = {{1,1}, {1,-1}, {1,0}, {0,1}, {0,-1}, {-1,1}, {-1,-1}, {-1,0}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        pair<int,int> dest = {n-1, n-1};

        queue<pair<int,int>> q;
        q.push({0,0});
        int steps = 1;
        grid[0][0] = 2;

        while(!q.empty()){
            int size = q.size();

            for(int x = 0; x<size; x++){
                pair<int, int> f = q.front();
                q.pop();

                if (f == dest) return steps;

                int i = f.first;
                int j = f.second;

                for(int k = 0; k<8; k++){
                    int ii = i + next[k][0];
                    int jj = j + next[k][1];
                    if(ii < n && jj < n && ii>=0 && jj>=0 && grid[ii][jj]==0){ 
                        q.push({ii,jj});
                        grid[ii][jj] = 2;
                    }
                }
            }
                steps++;
        }
        return -1;        
    }
};