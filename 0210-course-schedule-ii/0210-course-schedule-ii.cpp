class Solution {
public:
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;

    stack<int> st;
    bool isCycleFound = false;
    void dfs(int src, unordered_map<int, bool> &pathVisited){
        visited[src] = true;
        pathVisited[src] = true;

        for(auto neighbour : adj[src]){
            if(visited[neighbour] && pathVisited[neighbour]){
                isCycleFound = true;
                return;
            }
            if(!visited[neighbour]){
                if(isCycleFound){
                    return;
                } else {  
                    dfs(neighbour, pathVisited);
                }
               
            }
        }

        st.push(src);
        pathVisited[src] = false;
        return;
    }

    bool findCycle(int src, unordered_map<int, bool> pathVisited){
        visited[src] = true;
        pathVisited[src] = true;

        for(auto neighbour : adj[src]){
            if(visited[neighbour] && pathVisited[neighbour]){
                return true;
            } else if(!visited[neighbour]){
                bool isCycle = findCycle(neighbour, pathVisited);
                if(isCycle){
                    return true;
                }
            }
        }
        pathVisited[src] = false;

        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, bool> pathVisited;
        
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        // for(int i=0;i<numCourses;i++){
        //     if(!visited[i]){
        //         if(findCycle(i, pathVisited)){
        //            return {};
        //         }
        //     }
        // }

        // visited.clear();

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                dfs(i, pathVisited);
                if(isCycleFound){
                    return {};
                }
            }
        }

        vector<int> result;

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};