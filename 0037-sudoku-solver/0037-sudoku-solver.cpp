class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char val) {

        for (int i = 0; i < board.size(); i++) {
            if (board[row][i] == val) {
                return false;
            }

            if (board[i][col] == val) {
                return false;
            }

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, i, j, ch)) {

                            board[i][j] = ch;
                            if (solve(board) == true) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};