class Solution {
public:
    unordered_map<int, bool> visited;
    unordered_map<int, bool> pathVisited;
    stack<int> st;
    bool detetCycle(int src, unordered_map<int, list<int>> &adj){
        visited[src] = true;
        pathVisited[src] = true;

        for(auto neighbour : adj[src]){
            if(visited[neighbour] && pathVisited[neighbour]){
                return true;
            } else if(!visited[neighbour]){
                bool isCyclePresent = detetCycle(neighbour, adj);
                if(isCyclePresent){
                    return true;
                }
            }
        }

        pathVisited[src] = false;
        st.push(src);

        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;

        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(detetCycle(i, adj)){
                    return {};
                }
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};