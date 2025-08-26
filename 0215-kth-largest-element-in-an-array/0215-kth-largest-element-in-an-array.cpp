class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i = 0; i<n; i++){
            minHeap.push(nums[i]);
        }

        for(int i = 0; i<(n - k); i++){
            minHeap.pop();
        }
        
        return minHeap.top();
    }
};