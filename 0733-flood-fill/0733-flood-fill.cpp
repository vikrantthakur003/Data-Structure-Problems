class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        queue<pair<int, int>> floodFill;
        floodFill.push({sr, sc});
        int originalColor = image[sr][sc];

        if(originalColor == color){
            return image;
        }

        image[sr][sc] = color;

        vector<pair<int, int>> directions{
            {-1, 0}, // up
            {1, 0}, // down
            {0, -1}, // left
            {0, 1} // right
        };

        while(!floodFill.empty()){
            int x = floodFill.front().first;
            int y = floodFill.front().second;
            
            floodFill.pop();

           for(auto dir : directions){
            int newX = x + dir.first;
            int newY = y + dir.second;

            if(newX >=0 && newX < m && newY >=0 && newY < n && image[newX][newY] == originalColor){
                image[newX][newY] = color;
                floodFill.push({newX, newY});
            } 
           }
        }

        return image;
    }
};