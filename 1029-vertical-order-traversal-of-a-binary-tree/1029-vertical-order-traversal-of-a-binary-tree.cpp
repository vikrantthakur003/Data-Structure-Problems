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
        map<int, map<int, vector<int>> > traverseNode; // level and horizontal value

        vector<vector<int>> result;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()){
            auto frontPair = q.front();
            q.pop();

            int lvl = frontPair.second.first;
            int hd = frontPair.second.second;
            TreeNode* node = frontPair.first;

            traverseNode[hd][lvl].push_back(node->val);
            
            if(node->left){
                q.push({node->left, {lvl + 1, hd - 1}});
            }

            if(node->right){
                q.push({node->right, {lvl + 1, hd + 1}});
            }
        }

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