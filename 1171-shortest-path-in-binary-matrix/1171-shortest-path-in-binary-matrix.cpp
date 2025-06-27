class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] != 0 || grid[n-1][n-1] != 0){
            return -1;
        }
       
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));

        vector<pair<int, int>> directions = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1},
            {1, 1},
            {-1, 1},
            {1, -1},
            {-1, -1}
        };

        minHeap.push({1, {0, 0}}); // distance, x, y
        distance[0][0] = 1;

        while(!minHeap.empty()){
            auto frontpair = minHeap.top();
            minHeap.pop();

            int nodeDistance = frontpair.first;
            int x = frontpair.second.first;
            int y = frontpair.second.second;

            for(auto dir : directions){
                int newX = x + dir.first;
                int newY = y + dir.second;

                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 0){
                    int newDistance = nodeDistance + 1;
                    if(newDistance < distance[newX][newY]){
                        distance[newX][newY] = newDistance;
                        minHeap.push({newDistance, {newX, newY}});
                    }
                }
            }
        }

        return distance[n-1][n-1] == INT_MAX ? -1 : distance[n-1][n-1];
    }
};