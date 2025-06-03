class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();


        
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++){
            // first col
            if(grid[i][0] == 1){
                q.push({i, 0});
            }

            // last col
            if(grid[i][m-1] == 1){
                q.push({i, m-1});
            }
        }

        for(int j=0;j<m;j++){

            // first row
            if(grid[0][j] == 1){
                q.push({0, j});
            }

            // last row
            if(grid[n-1][j] == 1){
                q.push({n-1, j});
            }
        }

        vector<pair<int, int>> directions = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
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

        int numberOfLandCell = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    grid[i][j] = 1;
                } else if(grid[i][j] == 1) {
                    numberOfLandCell++;
                }
            }
        }

        return numberOfLandCell;
    }
};