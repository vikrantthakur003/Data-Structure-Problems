class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {

        int i = 0;
        int j = 0;
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> result;

        int k = 0;
        while (i < n && j < m) {
            vector<int> temp;
            if (nums1[i][0] == nums2[j][0]) {
                temp.push_back(nums1[i][0]);
                temp.push_back(nums1[i][1] + nums2[j][1]);

                i++;
                j++;
            } else if (nums1[i][0] < nums2[j][0]) {
                temp.push_back(nums1[i][0]);
                temp.push_back(nums1[i][1]);

                i++;
            } else {
                temp.push_back(nums2[j][0]);
                temp.push_back(nums2[j][1]);
                j++;
            }

            result.push_back(temp);
        }

        while (i < n) {
            result.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }

        while (j < m) {
            result.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }

        return result;
    }
};