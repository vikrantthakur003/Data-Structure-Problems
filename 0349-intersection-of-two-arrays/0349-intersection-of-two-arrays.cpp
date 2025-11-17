class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int s1 = 0;
        int s2 = 0;

        while(s1 < nums1.size() && s2 < nums2.size()){
            if(nums1[s1] == nums2[s2]){
                st.insert(nums1[s1]);
                s1++;
                s2++;
            } else if(nums1[s1] < nums2[s2]){
                s1++;
            } else {
                s2++;
            }
        }

        vector<int> ans;
        for(auto itr : st){
            ans.push_back(itr);
        }

        return ans;
    }
};