class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int count = 0; 
        int n = arr.size();
        vector<int> result;
       
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(int i = 0; i<n; i++){
            minheap.push(arr[i]);
        }

        unordered_map<int, int> mp; // element, rank;
        while(!minheap.empty()){
            int topElement = minheap.top();
            minheap.pop();

            if(mp.find(topElement) == mp.end()){
                count++;
                mp[topElement] = count;
            }
        }

        for(int i = 0; i<n; i++){
            result.push_back(mp[arr[i]]);
        }

        return result;
    }
};