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
        if(root == nullptr){
            return 0;
        }

        int leftHeight = heightOfTree(root->left);
        int rightHeight = heightOfTree(root->right);

        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        bool isLeftBalancedTree = isBalanced(root->left);
        bool isRightBalancedTree = isBalanced(root->right);

        bool diff = abs(heightOfTree(root->left) - heightOfTree(root->right)) <= 1;


        return isLeftBalancedTree && isRightBalancedTree && diff;
    }
};