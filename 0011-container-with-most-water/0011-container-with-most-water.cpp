class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int s = 0;
        int e = height.size() - 1;
        int maxxArea = INT_MIN;

        while(s < e){

            int l = min(height[s], height[e]);
            int b = e - s;

            int area = l * b;
            if(maxxArea < area){
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