class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, list<pair<int, int>>> adj;

        for(int i=0;i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v, w});
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

        vector<int> stops(n, INT_MAX);
        minHeap.push({0, {src, 0}});

        while(!minHeap.empty()){
            auto frontpair = minHeap.top();
            minHeap.pop();
            
            int nodeDistance= frontpair.first;
            int node = frontpair.second.first;
            int nodeStop = frontpair.second.second;

            if(node == dst){
                return nodeDistance;
            }

            if(nodeStop > k || nodeStop >= stops[node]) continue;

            stops[node] = nodeStop;

            for(auto neighbour : adj[node]){
                int neighbourNode = neighbour.first;
                int neighbourDistance = neighbour.second + nodeDistance;

                minHeap.push({neighbourDistance, {neighbourNode, nodeStop + 1}});
            }
        }

        return -1;
    }
};