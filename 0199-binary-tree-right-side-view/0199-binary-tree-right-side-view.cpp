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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        map<int, int> traverseNode;

        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));

        while(!q.empty()){
            pair<TreeNode*, int> frontPair = q.front();
            q.pop();

            TreeNode* frontNode = frontPair.first;
            int lvl = frontPair.second;

            traverseNode[lvl] = frontNode->val;

            if(frontNode->left){
                q.push(make_pair(frontNode->left, lvl + 1));
            }

            if(frontNode->right){
                q.push(make_pair(frontNode->right, lvl + 1));
            }
        }

        vector<int> result;
        for(auto itr : traverseNode){
            result.push_back(itr.second);
        }

        return result;
    }
};