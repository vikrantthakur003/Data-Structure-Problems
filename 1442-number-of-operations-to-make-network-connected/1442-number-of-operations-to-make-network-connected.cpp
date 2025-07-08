class DisjointSet{
    vector<int> size, parent;
public:
    DisjointSet(int n){
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int getParent(int u){
        return parent[u];
    }
    int findParent(int u){
        if(parent[u] == u){
            return u;
        }

        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v){
        int ultimateParentU = findParent(u);
        int ultimateParentV = findParent(v);

        if(ultimateParentU == ultimateParentV){
            return;
        }

        if(size[ultimateParentV] < size[ultimateParentU]){
            parent[ultimateParentV] = ultimateParentU;
            size[ultimateParentU] += size[ultimateParentV];
        } else {
            parent[ultimateParentU] = ultimateParentV;
            size[ultimateParentV] += size[ultimateParentU]; 
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n > connections.size() + 1){
            return -1;
        }
        
        vector<pair<int, int>> adj;

        for(int i=0;i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj.push_back({u, v});
            adj.push_back({v, u});
        }

        int noOfExtraConnections = 0;
        DisjointSet ds(n + 1);
        for(auto itr : adj){
            int u = itr.first;
            int v = itr.second;

            if(ds.findParent(u) != ds.findParent(v)){
                ds.unionBySize(u, v);
            } else {
                noOfExtraConnections++;
            }
        }

        int noOfNonConnectedComponent = 0;
        for(int i=0;i<n;i++){
            if(ds.getParent(i) == i){
                noOfNonConnectedComponent++;
            }
        }


        return (noOfExtraConnections >= noOfNonConnectedComponent - 1) ? noOfNonConnectedComponent - 1 : -1;
    }
};