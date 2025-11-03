class Solution {
public:
    vector<vector<int>> result;
    void findCombinations(int ind, int k, int sum, vector<int> temp){

        if(sum == 0 && temp.size() == k){
            result.push_back(temp);
            return;
        }

        if(temp.size() > k){
            return;
        }

        if(ind > 9){
            return;
        }
        
        temp.push_back(ind);
        findCombinations(ind + 1, k, sum - ind, temp);

        temp.pop_back();
        findCombinations(ind + 1, k, sum, temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;

        findCombinations(1, k, n, temp);

        return result;
    }
};