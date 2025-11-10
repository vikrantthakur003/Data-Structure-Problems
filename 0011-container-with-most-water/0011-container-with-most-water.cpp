class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxxArea = INT_MIN;

        int s = 0; 
        int e = height.size() - 1;

        while(s < e){
            int h = min(height[s], height[e]);
            int b = e - s;

            int area = h*b;
            if(area > maxxArea){
                maxxArea = area;
            } 

            if(height[s] < height[e]){
                s++;
            } else if(height[s] > height[e]){
                e--;
            } else {
                s++;
                e--;
            }
        }

        return maxxArea;
    }
};