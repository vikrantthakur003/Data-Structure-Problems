class DisjointSet {
    vector<int> size, parent;

public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if (parent[u] == u) {
            return u;
        }

        return parent[u] = findParent(parent[u]);
    }

    int findSize(int u){
        return size[u];
    }

    void unionBySize(int u, int v) {
        int ultimateParentU = findParent(u);
        int ultimateParentV = findParent(v);

        if (ultimateParentU == ultimateParentV) {
            return;
        }

        if (size[ultimateParentU] > size[ultimateParentV]) {
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n * m);
        int largestArea = INT_MIN;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int node = i * m + j;

                    for (auto dir : directions) {
                        int newX = i + dir.first;
                        int newY = j + dir.second;

                        if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                            grid[newX][newY] == 1) {
                                int neighbourNode  = newX * m + newY;
                               ds.unionBySize(node, neighbourNode);
                        }
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    set<int> uniqueParent;
                    int x = i;
                    int y = j;
                    for(auto dir : directions){
                        int newX = x + dir.first;
                        int newY = y + dir.second;

                        if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1){
                            int node = newX * m + newY;
                            int ultimateParent = ds.findParent(node);
                            uniqueParent.insert(ultimateParent);
                        }
                    }
                    int size = 1;
                    for(auto parent : uniqueParent){
                        size += ds.findSize(parent); // 1 for currect value of 0's
                    }
                    largestArea = max(largestArea, size);
                }
            }
        }

        // if all 1's pressent in matrix then we just go all cell and check in disjoint set
        for(int cellNo = 0; cellNo < n * m; cellNo++){
            int ultimateParent = ds.findParent(cellNo);
            int size = ds.findSize(ultimateParent);

            largestArea = max(largestArea, size);
        }

        return largestArea;
    }
};