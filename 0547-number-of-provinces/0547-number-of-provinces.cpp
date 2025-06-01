class Solution {
public:
    void dfsTraversal(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int src){
        visited[src] = true;

        for(auto neighbour : adj[src]){
            if(!visited[neighbour]){
                dfsTraversal(adj, visited, neighbour);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, list<int>> adj;

        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        unordered_map<int, bool> visited;
        int countProvinces = 0;

        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                countProvinces++;
                dfsTraversal(adj, visited, i);
            }
        }

        return countProvinces;
    }
};