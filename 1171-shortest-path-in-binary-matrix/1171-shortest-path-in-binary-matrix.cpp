class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] != 0) {
            return -1;
        }

        if (grid[n - 1][n - 1] != 0) {
            return -1;
        }

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        q.push({0, 0});
        visited[0][0] = true;

        int lengthOfclearPath = 1;

        vector<pair<int, int>> directions = {{-1, -1}, {1, 1}, {1, -1}, {-1, 1},
                                             {-1, 0},  {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                pair<int, int> frontpair = q.front();
                q.pop();

                int x = frontpair.first;
                int y = frontpair.second;

                if ((x == n - 1) && (y == n - 1)) {
                    return lengthOfclearPath;
                }

                for (auto dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                        grid[newX][newY] == 0) {
                        if (!visited[newX][newY]) {
                            visited[newX][newY] = true;
                            q.push({newX, newY});
                        }
                    }
                }
            }
            lengthOfclearPath++;
        }

        return -1;
    }
};