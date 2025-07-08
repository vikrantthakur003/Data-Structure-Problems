class Disjoinset{
    vector<int> size, parent;
    public:
    
    Disjoinset(int n){
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
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

        if(size[ultimateParentU] > size[ultimateParentV]){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mapWithMail;
        int n = accounts.size();

        Disjoinset ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size(); j++){
               string mail = accounts[i][j];

               if(mapWithMail.find(mail) == mapWithMail.end()){
                    mapWithMail[mail] = i;
               } else {
                    ds.unionBySize(i, mapWithMail[mail]);
               }
            }
        }


        unordered_map<int, vector<string>> adj(n);

        for(auto itr : mapWithMail){
            string mail = itr.first;
            int node = ds.findParent(itr.second);

            adj[node].push_back(mail);
        }

        vector<vector<string>> result;
        for(int i=0;i<n;i++){
            if(adj[i].size() == 0) continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            sort(adj[i].begin(), adj[i].end());

            for(auto itr : adj[i]){
                temp.push_back(itr);
            }

            result.push_back(temp);
        }

        return result;
    }
};