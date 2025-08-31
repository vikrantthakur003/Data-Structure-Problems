class KthLargest {
public:
    int k;
    vector<int> nums;
    priority_queue<int, vector<int>, greater<int>> minheap;

    int findKthLargestElement(int k, vector<int>&nums){
        if(nums.size() == 0){
            return -1;
        }

        for(int i = 0; i<k && i<nums.size(); i++){
            minheap.push(nums[i]);
        }

        for(int i = k; i<nums.size(); i++){

            if(minheap.top() < nums[i]){
                minheap.pop();
                minheap.push(nums[i]);
            }
        }

        return minheap.top();

    }
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;

        findKthLargestElement(this->k, this->nums);
    }
    
    int add(int val) {
        this->nums.push_back(val);
        if(minheap.empty() || minheap.size() < k){
            minheap.push(val);
        } else if(val > minheap.top()){
            minheap.pop();
            minheap.push(val);
        }

        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */