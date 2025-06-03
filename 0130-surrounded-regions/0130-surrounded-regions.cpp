class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;

        for(int j=0;j<m;j++){
            // first row
            if(board[0][j] == 'O'){
                q.push({0, j});
            } 
            if(board[n-1][j] == 'O'){
                q.push({n-1, j});
            }
        };

        for(int i=0;i<n;i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
            }

            if(board[i][m-1] == 'O'){
                q.push({i, m-1});
            }
        };

        vector<pair<int, int>> directions = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while(!q.empty()){
            pair<int,int> frontPair = q.front();
            q.pop();

            int x = frontPair.first;
            int y = frontPair.second;
            board[x][y] = 'S';

            for(auto dir : directions){
                int newX = x + dir.first;
                int newY = y + dir.second;

                if(newX >= 0 && newX < n && newY >= 0 && newY < m && board[newX][newY] == 'O'){
                    board[newX][newY] = 'S';
                    q.push({newX, newY});
                }
            }
        };


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};