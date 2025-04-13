/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int> > > traverseNode;

        queue<pair<TreeNode*, pair<int, int > > > q;

        q.push(make_pair(root, make_pair(0, 0)));

        while(!q.empty()){
            pair<TreeNode*, pair<int, int > > frontPair = q.front();
            q.pop();

            TreeNode* frontNode = frontPair.first;
            int hd = frontPair.second.first;
            int lvl = frontPair.second.second;

            traverseNode[hd][lvl].push_back(frontNode->val);

            if(frontNode->left){
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
            }

            if(frontNode->right){
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
            }
        }

        vector<vector<int>> result;
        for(auto itr : traverseNode){
            vector<int> col; // new column
            for(auto nodes : itr.second){
                vector<int> temp = nodes.second;
                sort(temp.begin(), temp.end());
                col.insert(col.end(), temp.begin(), temp.end()); // add all elements
            }
            result.push_back(col);
        }

        return result;
    }
};