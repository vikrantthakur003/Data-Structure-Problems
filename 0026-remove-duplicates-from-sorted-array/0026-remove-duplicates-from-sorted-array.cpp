class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int k = 0;

        for(auto currentElement : nums){
            if(k == 0 || (currentElement != nums[k - 1])){
                nums[k++] = currentElement;
            }
        }

        return k;
    }
};