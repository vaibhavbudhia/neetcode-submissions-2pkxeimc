class Solution {
public:
// vector<int> ans;

    bool dfs(int node, vector<int>& visited , vector<int>& path, vector<vector<int>>& graph){
        visited[node] = 1;
        path[node] = 1;

        for(int nbr : graph[node]){
            if(visited[nbr] == 0){
                bool cycle = dfs(nbr, visited, path, graph);
                if(cycle) return true;
            }
            else if(visited[nbr] && path[nbr]){
                return true;
            }
        }
        // ans.push_back(node);
        path[node] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        vector<int> path(numCourses, 0);

        for(int i = 0; i<prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            graph[b].push_back(a);
        }

        for(int i = 0; i<numCourses; i++){
            if(visited[i] == 0){
                bool cycle = dfs(i, visited, path, graph);\
                if(cycle) return false;
            }
        }
        // if (ans.size() != numCourses) return false;
        return true;
    }
};