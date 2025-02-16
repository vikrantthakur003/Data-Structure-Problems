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
    int findMaxDepth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int leftSideTraversal = findMaxDepth(root->left);
        int rightSideTraversal = findMaxDepth(root->right);

        return max(leftSideTraversal, rightSideTraversal) + 1;
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        return findMaxDepth(root);
    }
};