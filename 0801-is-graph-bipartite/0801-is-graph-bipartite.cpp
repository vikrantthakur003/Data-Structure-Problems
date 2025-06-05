class Solution {
public: 
    bool dfsTraversal(vector<vector<int>>& graph, unordered_map<int, pair<bool, char>> &visited, int src, char color){
        visited[src].first = true;
        visited[src].second = color;

        for(auto neighbour : graph[src]){
             if(visited[neighbour].first && visited[neighbour].second == color){
                return false;
             }
             if(!visited[neighbour].first){
                char neighbourColor = color == 'Y' ? 'G' : 'Y';
                bool isBipartiteGraph = dfsTraversal(graph, visited, neighbour,neighbourColor);
                if(!isBipartiteGraph){
                    return false;
                }
             }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, pair<bool, char>> visited;

        queue<pair<int, char>> q;

        for(int i=0;i<graph.size();i++){
            if(!visited[i].first){
                bool checkBipartite =  dfsTraversal(graph, visited, i, 'Y');
                if(!checkBipartite){
                    return false;
                }
            } 
        }

        return true;
    }
};