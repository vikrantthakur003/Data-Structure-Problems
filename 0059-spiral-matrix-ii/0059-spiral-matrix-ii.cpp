class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int cnt = 1;
        int direction = 0;
        int top = 0;
        int left = 0;
        int right = n - 1;
        int bottom = n - 1;
        
        while(cnt <= n * n){

            if(direction == 0){
                for(int i = left; i<=right; i++){
                    matrix[top][i] = cnt;
                    cnt++;
                }

                top++;
                direction = 1;
            } else if(direction == 1){
                for(int i = top; i<=bottom; i++){
                    matrix[i][right] = cnt;
                    cnt++;
                }
                right--;
                direction = 2;
            } else if(direction == 2){
                for(int i = right; i>=left; i--){
                    matrix[bottom][i] = cnt;
                    cnt++;
                }
                bottom--;
                direction = 3;
            } else if(direction == 3){
                for(int i = bottom; i>=top; i--){
                    matrix[i][left] = cnt;
                    cnt++;
                }
                left++;
                direction = 0;
            }
        }

        return matrix;
    }
};