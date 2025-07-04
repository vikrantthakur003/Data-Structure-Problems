class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minHeap;
        vector<int> distance(n + 1, INT_MAX);

        minHeap.push({0, k});
        distance[k] = 0;


        while(!minHeap.empty()){
            pair<int, int> frontpair = minHeap.top();
            minHeap.pop();

            int nodeDistance = frontpair.first;
            int node = frontpair.second;

            for(auto neighbour : adj[node]){
                int neighbourNode = neighbour.first;
                int neighbourDistance = neighbour.second + nodeDistance;

                if(neighbourDistance < distance[neighbourNode]){
                    distance[neighbourNode] = neighbourDistance;
                    minHeap.push({neighbourDistance, neighbourNode});
                }
            }
        }

        int maxValue = INT_MIN;
        for(int i=1;i<distance.size();i++){
            if(distance[i] == INT_MAX){
                return -1;
            } else {
                maxValue = max(maxValue, distance[i]);
            }
        }

        return maxValue;
    }
};