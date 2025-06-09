class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int totalFreshOranges = 0;
        int totalTimeToRotten = 0;
        int countOfRottenOranges = 0;


        queue<pair<int, int> > q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    totalFreshOranges++;
                }
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> directions = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while(!q.empty()){
            int size = q.size();

            while(size--){
                pair<int, int> frontPair = q.front();
                q.pop();

                int x = frontPair.first;
                int y = frontPair.second;

                for(auto dir : directions){
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1){
                        countOfRottenOranges++;
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                    }
                }
            }
            if(!q.empty()){
                totalTimeToRotten++;
            }
        }
        
        return totalFreshOranges == countOfRottenOranges ? totalTimeToRotten : -1;
    }
};