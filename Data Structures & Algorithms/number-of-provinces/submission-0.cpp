class Solution {
public:
    int r;
    int c;
    int count = 0;

    void bfs(int i, int j, vector<vector<int>>& isConnected) {
        
        isConnected[i][j] = 2;

        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()){
            pair<int,int> f = q.front();
            q.pop();

            auto city1 = f.first;
            auto city2 = f.second;
            
            for(int k=0; k<c; k++){
                if(isConnected[city1][k] == 1){
                    isConnected[city1][k] = 2;
                    q.push({city1, k});
                }
            }
            for(int k=0; k<r; k++){
                if(isConnected[k][city2] == 1){
                    isConnected[k][city2] = 2;
                    q.push({k, city2});
                }
            }
        }
        count++;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        r = isConnected.size();  
        c = isConnected[0].size();  

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(isConnected[i][j] == 1){
                    bfs(i, j, isConnected);
                }
            }             
        }
    return count;
    }

};