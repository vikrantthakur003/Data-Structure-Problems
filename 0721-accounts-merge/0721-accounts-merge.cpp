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
        
        unordered_map<string, int> mapMailWithNode;
        int n = accounts.size();

         Disjoinset ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];

                if(mapMailWithNode.find(mail) == mapMailWithNode.end()){
                    mapMailWithNode[mail] = i;
                } else { // if already exists in my map then connect node with map value and Ith value
                    ds.unionBySize(i, mapMailWithNode[mail]);
                }
            }
        }

        unordered_map<int, vector<string>> mergedMails(n);
        for(auto itr : mapMailWithNode){
            string mail = itr.first;
            int node = ds.findParent(itr.second); // find ultimate parent of index

            mergedMails[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedMails[i].size() == 0) continue;
            sort(mergedMails[i].begin(), mergedMails[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto itr : mergedMails[i]){
                temp.push_back(itr);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};