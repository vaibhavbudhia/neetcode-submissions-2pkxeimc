class Solution {
public:
    bool isConnected(string a, string b){
        int diff = 0;

        for(int i = 0; i<a.size(); i++){
            if(a[i] != b[i]) diff++;
        }

        return diff == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>&
wordList) {

        auto it = find(wordList.begin(), wordList.end(), endWord);
        if(it == wordList.end()) return 0;
        
        int n = wordList.size();
        vector<vector<int>> graph(n+1);

//form the graph with only 1 char differing
        for(int i = 0; i<n; i++){
            if(isConnected(beginWord, wordList[i]))
               graph[0].push_back(i + 1);
               graph[i + 1].push_back(0);
        }

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if (isConnected(wordList[i], wordList[j])){
                    graph[i+1].push_back(j+1);
                    graph[j+1].push_back(i+1);
                }
            }
        }

//get the endID
        int endID = -1;

        for(int i = 0; i<n; i++){
            if(wordList[i] == endWord){
                endID = i+1;
                break; 
            }        
        }

//bfs
    vector<int> visited(n+1,0);

    queue<int> q;
    q.push(0);
    visited[0] = 1;
    int steps = 1;

    while(!q.empty()){
        int size = q.size();

        for(int i = 0; i<size; i++){
            int f = q.front();
            q.pop();

        if(f == endID) return steps;

            for(int nbr : graph[f]){
                if(!visited[nbr]){
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
        steps++;
    }
    return 0;
    }
};
