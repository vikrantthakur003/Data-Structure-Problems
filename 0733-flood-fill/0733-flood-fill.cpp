class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startingNodeColor = image[sr][sc];

        if(startingNodeColor == color){
            return image;
        }

        queue<pair<int, int>> q;
        image[sr][sc] = color;
        q.push({sr, sc});

        while(!q.empty()){
            pair<int, int> frontPair = q.front();
            q.pop();

            vector<pair<int, int>> directions = {
                {-1, 0},
                {1, 0},
                {0, -1},
                {0, 1}
            };
            int x = frontPair.first;
            int y = frontPair.second;

            for(auto dir : directions){
                int newX = x + dir.first;
                int newY = y + dir.second;

                if(newX >= 0 && newX < image.size() && newY >= 0 && newY < image[0].size() && image[newX][newY] == startingNodeColor){
                    image[newX][newY] = color;
                    q.push({newX, newY});
                }
            }
        }

        return image;
    }
};