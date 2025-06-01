class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rottenMinutes = 0;
        int totalRottanOrganes = 0;
        int countRottonOrganes = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != 0) {
                    totalRottanOrganes++;
                }
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int rotanOrganesSize = q.size();
            countRottonOrganes += rotanOrganesSize;

            while (rotanOrganesSize--) {
                pair<int, int> frontPair = q.front();
                q.pop();
                int x = frontPair.first;
                int y = frontPair.second;

                vector<pair<int, int>> directions = {
                    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (auto dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    if (newX < grid.size() && newX >= 0 && newY >= 0 &&
                        newY < grid[0].size() && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                    }
                }
            }

            if(!q.empty()){
                rottenMinutes++;
            }
        }

        return (countRottonOrganes == totalRottanOrganes) ? rottenMinutes : -1;
    }
};