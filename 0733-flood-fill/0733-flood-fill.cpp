class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        if (image[sr][sc] == color) {
            return image;
        }

        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        int startingNodeColor = image[sr][sc];

        image[sr][sc] = color;

        vector<pair<int, int>> directions ={
            {-1, 0},
            {1, 0},
            {0, 1},
            {0, -1}
        };


        while(!q.empty()){
            pair<int, int> frontPair = q.front();
            q.pop();
            int x = frontPair.first;
            int y = frontPair.second;

           for(auto dir : directions){
                int newX = x + dir.first;
                int newY = y + dir.second;

                if(newX >= 0 && newX < n && newY >= 0 && newY < m && image[newX][newY] == startingNodeColor){
                    image[newX][newY] = color;
                    q.push({newX, newY});
                }
           }
        }

        return image;
    }
};