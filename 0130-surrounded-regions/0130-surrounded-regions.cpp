class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;

        int n = board.size();
        int m = board[0].size();

      
        for(int i=0;i<m;i++){
              // first rows
            if(board[0][i] == 'O'){
                q.push({0, i});
            }
            // last rows
            if(board[n-1][i] =='O'){
                q.push({n-1, i});
            }
        }

        for(int i=0;i<n;i++){
            // first col
            if(board[i][0] == 'O'){
                q.push({i, 0});
            }

            // last col
            if(board[i][m-1] == 'O'){
                q.push({i, m-1});
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

            board[x][y] = 'S';

            for(auto dir : directions){
                int newX = x + dir.first;
                int newY = y + dir.second;

                if(newX >= 0 && newX < n && newY >= 0 && newY < m && board[newX][newY] == 'O'){
                    q.push({newX, newY});
                    board[newX][newY] = 'S';
                }
            }
        }

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