class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore's voting algorithms
        int ele;
        int count = 0;

        for(int i=0;i<nums.size();i++){
            if(count == 0){
                 count = 1;
                ele = nums[i];
            }else if(nums[i] == ele){
                count++;
            }else{
                count--;
            }
        }

        int checkMajorityElement = 0;
        for(int i=0;i<nums.size();i++){
            if(ele == nums[i]){
                checkMajorityElement++;
            }
        }
        if(checkMajorityElement > (nums.size()/2)){
            return ele;
        }
        return -1;
    }
};