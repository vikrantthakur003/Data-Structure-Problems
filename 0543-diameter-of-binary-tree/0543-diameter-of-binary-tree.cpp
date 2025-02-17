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
    int diameter = 0;
    int findHeight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int leftTree = findHeight(root->left);
        int rightTree = findHeight(root->right);

        diameter = max(diameter, leftTree + rightTree);

        return max(leftTree, rightTree) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        findHeight(root);
        return diameter;
    }
};