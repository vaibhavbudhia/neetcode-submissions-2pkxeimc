class Solution {
public:
    int r;
    int c;
    int count = 0;

    void bfs(int i, int j, vector<vector<int>>& isConnected) {
        
        isConnected[i][j] = 2;

        queue<int> q;
        q.push(j);

        while(!q.empty()){
            int city2 = q.front();
            q.pop();

            for(int k=0; k<r; k++){
                if(isConnected[k][city2] == 1){
                    isConnected[k][city2] = 2;
                    q.push(k);
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