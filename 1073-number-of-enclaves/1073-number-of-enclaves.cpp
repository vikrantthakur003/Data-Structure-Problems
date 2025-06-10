class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<m;i++){
            // first row
            if(grid[0][i] == 1){
                q.push({0, i});
            }

            if(grid[n-1][i] == 1){
                q.push({n-1, i});
            }
        }

        for(int i=0;i<n;i++){
            // first col
            if(grid[i][0] == 1){
                q.push({i, 0});
            }

            if(grid[i][m-1] == 1){
                q.push({i, m-1});
            }
        }

        vector<pair<int, int>> directions = {
            {-1, 0},
            {1, 0},
            {0, 1},
            {0, -1}
        };

        while(!q.empty()){
            pair<int, int> frontPair = q.front();
            q.pop();

            int x = frontPair.first;
            int y = frontPair.second;

            grid[x][y] = 2;

            for(auto dir : directions){
                int newX = x + dir.first;
                int newY = y + dir.second;

                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1){
                    grid[newX][newY] = 2;
                    q.push({newX, newY});
                }
            }
        }

        int numerOfLandCells = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    numerOfLandCells++;
                }
            }
        }

        return numerOfLandCells;
    }
};