class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> result(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    result[i][j] = 0;
                }
            }
        }

          vector<pair<int, int>> directions = {
                {-1, 0}, {1, 0}, {0, -1}, {0, 1}
            };

        while (!q.empty()) {
            pair<int, int> frontPair = q.front();
            q.pop();

            int x = frontPair.first;
            int y = frontPair.second;
        
            for (auto dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                    result[newX][newY] == -1) {
                    result[newX][newY] = result[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }

        return result;
    }
};