class Solution {
public:
    // unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    unordered_map<int, pair<bool, int>> pathVisited; // node, (true, count)

    int maxValue = -1;
    void dfsTraversal(int src, int count, vector<int>& edges){
        visited[src] = true;
        pathVisited[src] = { true, count };

        
        int neighbour = edges[src];
        if(neighbour != -1){
            if(!visited[neighbour]){
                dfsTraversal(neighbour, count + 1, edges);
            } else if(pathVisited[neighbour].first){
                int diff = count - pathVisited[neighbour].second + 1;
                maxValue = max(maxValue, diff);
            }
        }
 
        pathVisited[src].first = false;
        // pathVisited[src].second = 0;
        return;
    }
    int longestCycle(vector<int>& edges) {
        
        // for(int i=0;i<edges.size();i++){
        //     if(edges[i] != -1){
        //         adj[i].push_back(edges[i]);
        //     }
        // }

        for(int i=0;i<edges.size();i++){
            if(!visited[i]){
                dfsTraversal(i, 1, edges);
            }
        }

        return maxValue;
    }
};