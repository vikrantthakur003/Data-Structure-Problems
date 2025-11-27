class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i <=(n - k); i++) {
            vector<int> temp;

            for (int start = i; start < (i + k); start++) {
                temp.push_back(nums[start]);
            }

            unordered_map<int, int> mp;
            for (int i = 0; i < temp.size(); i++) {
                mp[temp[i]]++;
            }

            vector<pair<int, int>> freVec(mp.begin(), mp.end());
        sort(freVec.begin(), freVec.end(), [](auto &a, auto &b){
                if (a.second != b.second)
                    return a.second > b.second;
                return a.first > b.first;
        });

        int x_sum = 0;
        int elements = 0;

        for(auto itr : freVec){
                if (elements < x) {
                    x_sum += itr.first * itr.second;
                    elements++;
                } else {
                    break;
                }
        }

        result.push_back(x_sum);
        }

        return result;
    }
};