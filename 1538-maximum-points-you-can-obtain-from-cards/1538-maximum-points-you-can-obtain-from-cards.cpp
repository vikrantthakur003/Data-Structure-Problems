class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        
        int leftSum = 0;
        int rightSum = 0;

        for(int i = 0; i<k; i++){
            leftSum += arr[i];
        }

        int maxSum = leftSum;

        int rightIndex = arr.size() - 1;
        for(int i = k - 1; i>=0; i--){
            leftSum -= arr[i]; // substract from left window

            rightSum += arr[rightIndex]; // addition from right window
            rightIndex--;

            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};