class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int k = 0;
        for(auto currentElement : nums){
            if(currentElement != val){
                nums[k++] = currentElement;
            }
        }
        return k;
    }
};