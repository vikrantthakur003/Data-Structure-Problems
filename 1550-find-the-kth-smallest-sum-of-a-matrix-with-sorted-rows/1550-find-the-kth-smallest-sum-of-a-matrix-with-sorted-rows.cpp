class Solution {
public:
    vector<int> mergeList(vector<int> &a, vector<int> &b, int k){

        priority_queue<int, vector<int>, greater<int>> minheap;

        for(auto x : a){
            for(auto y : b){
                minheap.push(x + y);
            }
        }


        vector<int> result;
        for(int i = 0; i<k && !minheap.empty(); i++){
            result.push_back(minheap.top());
            minheap.pop();
        }

        return result;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        
        vector<int> current = mat[0];

        for(int i = 1; i<mat.size(); i++){
            current = mergeList(current, mat[i], k);
        }

        return current[k - 1];
    }
};