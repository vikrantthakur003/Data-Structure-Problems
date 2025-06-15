class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        unordered_map<int, list<pair<int, int>>> adj;

        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v, w});
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        vector<int> stops(n, INT_MAX);

        q.push({0, src, 0}); // stop, node, dist
        // stops[src] = 0;

        while (!q.empty()) {
            auto [cost, node, stop] = q.top();
            q.pop();

            if (node == dst) {
                return cost;
            }

            if (stop > k || stop >= stops[node]) continue;
            stops[node] = stop;


            for (auto neighbour : adj[node]) {
                int nextNeighbour = neighbour.first;
                int neighbourCost = neighbour.second + cost;
                    // q.push({stop + 1, nextNeighbour, neighbourCost});
                q.push({neighbourCost, nextNeighbour, stop + 1});
            }
        }

        return -1;
    }
};