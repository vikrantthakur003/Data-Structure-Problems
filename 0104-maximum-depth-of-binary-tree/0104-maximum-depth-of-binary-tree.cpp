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
    int heightOfTree(TreeNode* root){
        // Base Condition
        if(root == NULL){
            return 0;
        }
        // Hypothesis
        int leftHeightOfTree = heightOfTree(root->left);
        int rightHeightOfTree = heightOfTree(root->right);

        // Induction
        return max(leftHeightOfTree, rightHeightOfTree) + 1;
    }
    int maxDepth(TreeNode* root) {
        return heightOfTree(root);
    }
};