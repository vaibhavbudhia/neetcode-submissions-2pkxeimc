class Solution {
public:
    
bool dfs(int node, vector<int>& visited, vector<int>& path,         vector<vector<int>>& graph){

        visited[node] = 1;
        path[node] = 1;

        for(int nbr : graph[node]){
            if(!visited[nbr]){
                bool ans = dfs(nbr, visited, path, graph);
                if(ans) return true;
            }
            else if (visited[nbr] && path[nbr]){
                return true;
            }
        } 
        path[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        

        vector<int> visited(numCourses,0);
        vector<int> path(numCourses,0);
        vector<vector<int>> graph(numCourses);

        for(int i = 0; i<n; i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            graph[b].push_back(a);
        }

        for(int i = 0; i<numCourses; i++){
            if(!visited[i]){
            bool cycle = dfs(i, visited, path, graph);
            if(cycle) return false;
            }
        }

        // for(int x : visited){
        //     if(x == 0) return false;
        // }
        return true;
    }
};
