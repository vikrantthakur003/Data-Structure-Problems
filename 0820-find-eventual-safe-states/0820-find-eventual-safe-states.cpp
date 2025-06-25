class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, list<int>> adj;
        vector<int> indegree(graph.size(), 0);
        // reverse graph
        for(int i=0;i<graph.size();i++){
            for(auto neighbour : graph[i]){
                adj[neighbour].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for(auto neighbour : adj[frontNode]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};