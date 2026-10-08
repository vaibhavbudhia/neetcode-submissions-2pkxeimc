class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for(int i = 0; i<prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            indegree[a]++;
            graph[b].push_back(a);
        }

        queue<int> q;

        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0)
            q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){
            int f = q.front();
            ans.push_back(f);
            q.pop();
            
            for(int nbr : graph[f]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        if(ans.size()!= numCourses) return {};
        return ans;
    }
};
