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
    int totalNodes = 0;
    void helper(TreeNode* root){
        if(root == nullptr){
            return;
        }
        totalNodes++;
        helper(root->left);
        helper(root->right);
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        helper(root);
        return totalNodes;
    }
};