class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        if(n == 1 && m == 1){
            return 0;
        }

        if(n == 1 && m > 1){
            int maxValue = 0;
            for(int i=0;i<m-1;i++){
                int diff = abs(heights[0][i] - heights[0][i+1]);
                if(diff > maxValue){
                    maxValue = max(maxValue, diff);
                }
            }

            return maxValue;
        }

        if(m == 1 && n > 1){
            int maxValue = 0;
            for(int i=0;i<n-1;i++){
                int diff = abs(heights[i][0] - heights[i+1][0]);
                if(diff > maxValue){
                    maxValue = max(maxValue, diff);
                }
            }

            return maxValue;
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        vector<pair<int, int>> directions = {
            {-1,0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        minHeap.push({0, {0, 0}});
        distance[0][0] = 0;

        while(!minHeap.empty()){
            auto frontpair = minHeap.top();
            minHeap.pop();

            int nodeDistance = frontpair.first;
            int x = frontpair.second.first;
            int y = frontpair.second.second;

            if(x == n-1 && y == m -1){
                return nodeDistance;
            }

            for(auto dir : directions){
                int newX = x + dir.first;
                int newY = y + dir.second;

                if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                    int diff = abs(heights[x][y] - heights[newX][newY]);

                    int newEffort = max(nodeDistance, diff);

                    if(newEffort < distance[newX][newY]){
                        distance[newX][newY] = newEffort;
                        minHeap.push({newEffort, {newX, newY}});
                    }
                }
            }
        }

        return distance[n-1][m-1];
    }
};