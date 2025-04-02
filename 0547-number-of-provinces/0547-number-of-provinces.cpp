class Solution {
public:
    void dfsTraversal(unordered_map<int, bool> &visited, vector<vector<int>> &adj, int startNode){
        visited[startNode] = true;

        for(auto neighbour : adj[startNode]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                dfsTraversal(visited, adj, neighbour);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, bool> visited;
        vector<vector<int>> adjLs(n);
        int provincesCount = 0;

        // to change adjacency matrix to list 
        for(int i = 0;i<isConnected.size();i++) {
            for(int j = 0;j<isConnected.size();j++) {
                // self nodes are not considered
                if(isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }

        for(int i=0;i<adjLs.size();i++){
            if(!visited[i]){
                provincesCount++;
                dfsTraversal(visited, adjLs, i);
            }
        }

        return provincesCount;
    }
};