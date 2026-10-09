class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        // vector<int> visited(n,0);
        vector<int> res;

        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            indegree[i] = graph[i].size();
            if (indegree[i] == 1) {
                q.push(i);
                // visited[i] = 1;
            }
        }
int remaining = n;
        while (remaining > 2) {
            int size = q.size();
            remaining -= size;

            for (int i = 0; i < size; i++) {
                int f = q.front();
                q.pop();

                for (int nbr : graph[f]) {
                    // if(!visited[nbr]){
                    indegree[nbr] -= 1;
                    if (indegree[nbr] == 1) {
                        // visited[nbr] = 1;
                        q.push(nbr);
                        // }
                    }
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};