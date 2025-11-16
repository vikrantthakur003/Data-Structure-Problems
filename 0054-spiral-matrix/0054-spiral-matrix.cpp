class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        if(row == 0){
            return {};
        }

        int col = matrix[0].size();
        int left = 0;
        int right = col - 1;
        int top = 0;
        int bottom = row - 1;
        int direction = 0;

        vector<int> ans;
        while(left <= right && top <= bottom){

            if(direction == 0){

                for(int i = left; i<=right; i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
                direction = 1;
            } else if(direction == 1){

                for(int i = top; i<=bottom; i++){
                    ans.push_back(matrix[i][right]);
                }

                right--;
                direction = 2;
            } else if(direction == 2){

                for(int i = right; i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }

                bottom--;
                direction = 3;
            } else if(direction == 3){

                for(int i = bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
                direction = 0;
            }
        }

        return ans;
    }
};