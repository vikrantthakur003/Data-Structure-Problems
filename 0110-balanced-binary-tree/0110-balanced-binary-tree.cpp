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
    int findDepth(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int leftDepth = findDepth(root->left);
        int rightDepth = findDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }

        int leftSide = isBalanced(root->left);
        int rightSide = isBalanced(root->right);

        int diff = abs(findDepth(root->left) - findDepth(root->right)) <= 1;

        return leftSide && rightSide && diff;
    }
};