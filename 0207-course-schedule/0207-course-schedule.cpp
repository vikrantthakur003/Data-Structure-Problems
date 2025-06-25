class Solution {
public:
    unordered_map<int, bool> visited;
    unordered_map<int, bool> pathVisited;
    bool cycleDetect(int src, unordered_map<int, list<int>> &adj){
        visited[src] = true;
        pathVisited[src] = true;

        for(auto neighbour : adj[src]){
            if(visited[neighbour] && pathVisited[neighbour]){
                return true;
            } else if (!visited[neighbour]){
                bool isCyclePresent = cycleDetect(neighbour, adj);
                if(isCyclePresent){
                    return true;
                }
            } 
        }

        pathVisited[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(cycleDetect(i, adj)){
                    return false;
                }
            }
        }

        return true;
    }
};