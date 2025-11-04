class Solution {
public:
    bool solve(vector<vector<char>> &mat, int row, int col, int ind, string &word){
        if(ind >= word.size()){
            return true;
        }

        if(row < 0 || col < 0 || row >= mat.size() || col >= mat[0].size() || mat[row][col] != word[ind] || mat[row][col] == '#'){
            return false;
        }

        char ch = mat[row][col];
        mat[row][col] = '#';

        bool upSide = solve(mat, row - 1, col, ind + 1, word);
        bool rightSide = solve(mat, row, col + 1, ind + 1, word);
        bool leftSide = solve(mat, row, col - 1, ind + 1, word);
        bool downSide = solve(mat, row + 1, col, ind + 1, word);

        mat[row][col] = ch;
        return upSide || rightSide || leftSide || downSide;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(solve(board, i, j, 0, word)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};