class Solution {
public:
    vector<vector<string>> result;
    bool isSafe(int row, int col, vector<string> board, int n){
        // we are moving left to right into board so we just need to check onlly left side 3 direction no need to check right side 3 directions
        int dubRow = row;
        int dubCol = col;

        // check upper digonal
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }

        // check left Side
        row = dubRow;
        col = dubCol;

        while(col >= 0){
             if(board[row][col] == 'Q'){
                return false;
            }
            col--;
        }

        // check below diagonal
        row = dubRow;
        col = dubCol;
        while(row < n && col >= 0){
             if(board[row][col] == 'Q'){
                return false;
            }

            row++;
            col--;
        }

        return true;
    }
    void solve(vector<string> &board, int n, int col){
        if(col == n){
            result.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';

                solve(board, n, col + 1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string str(n, '.');

        for(int i = 0; i<n; i++){
            board[i] = str;
        }

        solve(board, n, 0);

        return result;
    }
};