class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, list<int>> revAdj;
        vector<int> inDegree(graph.size(), 0);

        for(int i=0;i<n;i++){
            for(auto it : graph[i]){
                revAdj[it].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> result;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            result.push_back(node);
            
            for(auto neighbour : revAdj[node]){
                inDegree[neighbour]--;
                
                if(inDegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};