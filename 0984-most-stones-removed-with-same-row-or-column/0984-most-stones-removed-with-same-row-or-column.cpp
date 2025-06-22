class DisjointSet{
    vector<int> size, parent;
    public:
    DisjointSet(int n){
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findParent(int u){
        if(u == parent[u]){
            return u;
        }

        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v){
        int ultimateParentU = findParent(u);
        int ultimateParentV = findParent(v);
        
        if(ultimateParentV == ultimateParentU){
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
    int removeStones(vector<vector<int>>& stones) {
        
        int noOfConnectStones = 0;
        int maxRow = 0, maxCol = 0;
        for (auto &stone : stones) {
            maxRow = max(maxRow, stone[0]);  // row
            maxCol = max(maxCol, stone[1]);  // col
        }

        DisjointSet ds(maxRow + maxCol + 1);
        for(auto itr : stones){
            int nodeRow = itr[0];
            int nodeCol = itr[1] + maxRow + 1;
            
            ds.unionBySize(nodeRow, nodeCol);
        }

        set<int> uniqueParent;
        for(auto itr : stones){
            int node = itr[0];
            uniqueParent.insert(ds.findParent(node));
        }

        return stones.size() - uniqueParent.size();
    }
};