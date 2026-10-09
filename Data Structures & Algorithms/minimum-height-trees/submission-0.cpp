class Solution {
public:
    vector<int> res;

    void bfs(int node, vector<vector<int>>& graph, int n) {
        vector<int> visited(n, 0);
        int depth = 0;

        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int f = q.front();
                q.pop();

                for (int nbr : graph[f]) {
                    if (!visited[nbr]) {
                        visited[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }
            depth++;
        }

        res[node] = depth;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> graph(n);

        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        res.resize(n, 0);

        for (int i = 0; i < n; i++) {
            bfs(i, graph, n);
        }

        int minH = INT_MAX;

        for (int i = 0; i < n; i++) {
            minH = min(minH, res[i]);
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (res[i] == minH) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};