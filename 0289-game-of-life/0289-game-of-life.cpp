class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<pair<int, int>> directions = {
            {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}
        };

        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> matrix(n, vector<int>(m, 0));
       
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){

                if(board[i][j] == 1){
                    
                    int noOfOnes = 0;
                    int noOfZeros = 0;
                    for(auto dir : directions){
                        int newX = i + dir.first;
                        int newY = j + dir.second;

                        if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                            if(board[newX][newY] == 1){
                                noOfOnes++;
                            } else {
                                noOfZeros++;
                            }
                        }
                    }

                    if(noOfOnes < 2){
                        matrix[i][j] = 0;
                    } else if(noOfOnes == 2 || noOfOnes == 3){
                        matrix[i][j] = 1;
                    } else if(noOfOnes > 3){
                        matrix[i][j] = 0;
                    } else {
                        matrix[i][j] = board[i][j];
                    }
                } else if(board[i][j] == 0){
                    int noOfOnes = 0;
                    for(auto dir : directions){
                        int newX = i + dir.first;
                        int newY = j + dir.second;

                        if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                            if(board[newX][newY] == 1){
                                noOfOnes++;
                            }
                        }
                    }

                    if(noOfOnes == 3){
                        matrix[i][j] = 1;
                    } else {
                        matrix[i][j] = board[i][j];
                    }
                }
            }
        }

        board = matrix;
    }
};