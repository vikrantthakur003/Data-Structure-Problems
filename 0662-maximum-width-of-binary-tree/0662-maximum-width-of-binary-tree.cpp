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
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = INT_MIN;
        if(root == nullptr){
            return -1;
        }
        queue<pair<TreeNode*, unsigned long long>> q;

        q.push({root, 0});

        while(!q.empty()){
            int queueSize = q.size();
            pair<TreeNode*, unsigned long long> frontPair = q.front();
            pair<TreeNode*, unsigned long long> lastPair = q.back();

            unsigned long long startIndexOfLevel = frontPair.second;
            unsigned long long endIndexOfLevel = lastPair.second;

            maxWidth = max(maxWidth, (int)(endIndexOfLevel - startIndexOfLevel)+1);

            while(queueSize--){
                pair<TreeNode*, unsigned long long> frontPair = q.front();
                 q.pop();

                TreeNode* frontNode = frontPair.first;
                unsigned long long frontIndex = frontPair.second;

                if(frontNode->left){
                    q.push({frontNode->left, 2*frontIndex + 1});
                }

                if(frontNode->right){
                    q.push({frontNode->right, 2*frontIndex + 2});
                }
            }
        }

        return maxWidth;
    }
};