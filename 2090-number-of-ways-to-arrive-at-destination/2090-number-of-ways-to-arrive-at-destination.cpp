class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        unordered_map<int ,list<pair<int, long long>>> adj;
        for(int i=0;i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            long long w = roads[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap;
        vector<long long> distance(n, LLONG_MAX);
        vector<int> ways(n, 0);

        minHeap.push({0, 0});
        distance[0] = 0;
        int numberOfWays = 0;
        ways[0] = 1;

        while(!minHeap.empty()){
            pair<long long, int> frontpair = minHeap.top();
            minHeap.pop();

            long long nodeDistance = frontpair.first;
            int node = frontpair.second;

            for(auto neighbour : adj[node]){
                int neighbourNode = neighbour.first;
                long long neighbourDistance = neighbour.second + nodeDistance;

                if(neighbourDistance < distance[neighbourNode]){
                    distance[neighbourNode] = neighbourDistance;
                    ways[neighbourNode] = ways[node];
                    minHeap.push({neighbourDistance, neighbourNode});
                } else if(neighbourDistance == distance[neighbourNode]){
                    ways[neighbourNode] = (ways[neighbourNode] + ways[node])% MOD;
                }
            }
        }

        return ways[n-1];
    }
};