class Solution {
public:

    vector<int> resultsArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i<=(n-k); i++){

            vector<int> temp;
            for(int j = i; j<(i + k); j++){
                temp.push_back(nums[j]);
            }

            bool isConsecutiveAndSorted = true;
            for(int x = 1; x<k; x++){
                if(temp[x] != temp[x - 1] + 1){
                    isConsecutiveAndSorted = false;
                    break;
                }
            }

            if(isConsecutiveAndSorted){
                auto it = max_element(temp.begin(), temp.end());
                ans.push_back(*it);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};