class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, 1e8));

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            distance[u][v] = w;
            distance[v][u] = w;
        }

        for (int i = 0; i < n; i++) {
            distance[i][i] = 0;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    distance[i][j] = min(distance[i][j],
                                         distance[i][via] + distance[via][j]);
                }
            }
        }

        int minCount = INT_MAX;
        int greatestCity = -1;
        for(int i=0;i<n;i++){
            int cityCount = 0;
            for(int j=0;j<n;j++){
                if(i != j && distance[i][j] <= distanceThreshold){
                    cityCount++;
                }
            }

            if(minCount >= cityCount){
                minCount = cityCount;
               greatestCity = i;
            }
        }

        return greatestCity;
    }
};